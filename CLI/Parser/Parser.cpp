#include "Parser.h"

//static member initialization
cli::Parser::StateDiagram cli::Parser::m_states;
cli::Parser::State cli::Parser::m_CurrentState = State::S_Start;

//PARSER CORE METHODS DEFINITIONS
cli::Parser::Parser() 
: m_lexer{}, m_syntaxAnalyzer{}, m_CommandFactory{std::make_unique<CommandCreator>()} {
    setStateDiagram();
};

void cli::Parser::setStateDiagram() {
    setStartState();
    setNameState();
    setOptionState();
    setArgumentState();
}

cli::Parser::CommandPtr cli::Parser::getCommand(std::istream& inputStream) {
    std::stringstream buffer;
    std::string line;
    std::getline(inputStream, line);
    buffer << line;
    
    return std::move((m_CommandFactory->CreateCommand(Parse(buffer))));
}

void cli::Parser::setStartState() {
    std::unordered_map<TokenType, State> startStateValue;
    startStateValue[TokenType::Name] = State::S_Name;
    startStateValue[TokenType::Option] = State::S_Dead;
    startStateValue[TokenType::Argument] = State::S_Dead;
    startStateValue[TokenType::Null] = State::S_Dead;

   m_states[State::S_Start] = std::move(startStateValue);
}

void cli::Parser::setNameState() {
    std::unordered_map<TokenType, State> nameStateValue;
    nameStateValue[TokenType::Name] = State::S_Name;
    nameStateValue[TokenType::Option] = State::S_Opt;
    nameStateValue[TokenType::Argument] = State::S_Dead;
    nameStateValue[TokenType::Null] = State::S_End;

   m_states[State::S_Name] = std::move(nameStateValue);

}

void cli::Parser::setOptionState() {
   std::unordered_map<TokenType, State> optionStateValue;
    optionStateValue[TokenType::Name] = State::S_Dead;
    optionStateValue[TokenType::Option] = State::S_Opt;
    optionStateValue[TokenType::Argument] = State::S_Arg;
    optionStateValue[TokenType::Null] = State::S_End;

    m_states[State::S_Opt] = std::move(optionStateValue);
}

void cli::Parser::setArgumentState() {
    std::unordered_map<TokenType, State> argumentStateValue;
    argumentStateValue[TokenType::Name] = State::S_Dead;
    argumentStateValue[TokenType::Option] = State::S_Dead;
    argumentStateValue[TokenType::Argument] = State::S_Arg;
    argumentStateValue[TokenType::Null] = State::S_End;

    m_states[State::S_Arg] = std::move(argumentStateValue);
}

const cli::Parser::State cli::Parser::pass(const Token& nextToken) {
    try {
        //const auto type = nextToken.second;
        const auto currState =  getNextState(nextToken);
        return currState;
        } catch(const Exception& cerr) {
            throw;
        }
}

const cli::Parser::State cli::Parser::getNextState(const Token& nextToken) const {
    const auto tokenType = nextToken.second;
    const auto nextState = m_states[m_CurrentState][tokenType];

    if (nextState == State::S_Dead) {
        const auto error  = getErrorType(nextToken);
        throw cli::InvalidSyntax_Cerr("Invalid Syntax", error, std::source_location::current());
    }

    return nextState;
}

const cli::Parser::ErrorType cli::Parser::getErrorType(const Token& nextToken) const noexcept {
    if (m_CurrentState == State::S_Name) {
        return (nextToken.second == TokenType::Option) ? ErrorType::T1 : ErrorType::T2;
    }

    if(m_CurrentState == State::S_Opt) {
        return (nextToken.second == TokenType::Name) ? ErrorType::T4 : ErrorType::T3;
    }

    if (m_CurrentState == State::S_Arg) {
        return (nextToken.second == TokenType::Name) ? ErrorType::T5 : ErrorType::T6;
    }
}


cli::CommandInfo cli::Parser::Parse(Text& text) {
    CommandInfo newCommand;
    try {
        parseText(text);
    } catch (const cli::Exception& err) {
        throw;
    }
    return m_ParsedCommand;
}

void cli::Parser::parseText(Text& text) {
    try {
        Token nextToken = m_lexer.getToken(text);

        while (nextToken.second != TokenType::Null) {
            m_CurrentState = pass(nextToken);
            m_syntaxAnalyzer.addTo(nextToken);
            nextToken = m_lexer.getToken(text);
        } 

    } catch(const cli::Exception& err) {
        throw;
    }

    const auto[name, options, arguments] = m_syntaxAnalyzer.getData();
    setCommandName(name);
    setCommandOptions(options);
    setCommandArguments(arguments);
}

void cli::Parser::setCommandName(const C_name& name) {
    m_ParsedCommand.m_name = name;
}

void cli::Parser::setCommandOptions(const C_options& options) {
    m_ParsedCommand.m_options = options;
}

void cli::Parser::setCommandArguments(const C_arguments& argument) {
    m_ParsedCommand.m_arguments = argument;
}

//PARSER::LEXER CORE METHODS DEFINITIONS
cli::Parser::Token cli::Parser::Lexer::getToken(Text& text) {
    try {
        return tokenize(text);
    } catch (cli::InvalidCharacter_Cerr& err) {
        throw;
    }
}

cli::Parser::Token cli::Parser::Lexer::tokenize(Text& text) {
    rawToken token = getRawToken(text);

    if (token == "") {
        return Token{"", TokenType::Null};
    }

    try {
        if (isWord(token)) {
            validateWord(token);
            return Token{token, TokenType::Name};
        }

        if (isOption(token)) {
            token.erase(0, 1);
            validateOption(token);
            return Token{token, TokenType::Option};
        }

        if (isArgument(token)) {
            token.erase(0, 1);
            token.erase(token.size() - 1, 1);
            validateArgument(token);
            return Token{token, TokenType::Argument};
        }
    } catch(cli::InvalidCharacter_Cerr& err) {
        throw;
    }

    return Token("", TokenType::Null); //will never reach here not to show as warning
}

cli::Parser::rawToken cli::Parser::Lexer::getRawToken(Text& text) {
    rawToken token;
    text >> token;
    return token;
}

bool cli::Parser::Lexer::isWord(const rawToken& token) const {
    const Character firstCharacter = token[0];
    return (isLetter(firstCharacter) && !hasDigit(token)) ? true : false;
}

bool cli::Parser::Lexer::isOption(const rawToken& token) const {
    const Character firstCharacter = token[0];
    return (isHyphen(firstCharacter)) ? true : false;
}

bool cli::Parser::Lexer::isArgument(const rawToken& token) const {
    //Argument = ^"[Word] | [digit] | [Symbol] "$
    return (isInQuotation(token)) ? true : false;
}

bool cli::Parser::Lexer::isLetter(const Character character) const{
    const char a = 97;
    const char z = 122;
    return (character >= a && character <= z) ? true : false;
}

bool cli::Parser::Lexer::hasDigit(const rawToken& token) const {
    
    for (size_t i{0}; i < token.size(); ++i) {
        if (std::isdigit(token[i])) {
            return true;
        }
    }
    return false;
}

bool cli::Parser::Lexer::isHyphen(const Character character) const {
    const char Hyphen = '-';
    return (character == Hyphen) ? true : false;
}

bool cli::Parser::Lexer::isInQuotation(const rawToken& token) const {
    const char firstCharacter = token[0];
    const char lastCharacter = token[token.size() - 1];
    const char QuoteMark = '"';

    return (firstCharacter == QuoteMark && lastCharacter == QuoteMark) ? true : false;
}

void cli::Parser::Lexer::validateWord(const rawToken& token) const {
    //Word = ^[a-z]+$
    for (size_t i{0}; i < token.size(); ++i) {
        if (!isLetter(token[i])) {
            throw cli::InvalidCharacter_Cerr("Invalid Character", token, i, std::source_location::current());
        }
    }
}

void cli::Parser::Lexer::validateOption(const rawToken& token) const {
    //Option = ^-[Word] | [digit] | [Symbol]
    //digit = ^[1-9]+[0 - 9]*$
    //Symbol = ! | / | * | () | % | @ | # | $ | = 

    if ((isZeroFirst(token) || hasInvalidCharacter(token))) {
        throw cli::InvalidCharacter_Cerr("Invalid Character", token, 0, std::source_location::current());
    }
}

bool cli::Parser::Lexer::isZeroFirst(const rawToken& token) const {
    const auto iterator = std::ranges::find_if(token, [] (const Character character){
        return std::isdigit(character);
    });

    if (iterator != token.end()) {
        return (isZero(*iterator)) ? true : false;
    }
    return false;
}

bool cli::Parser::Lexer::isZero(const Character character) const {
    const Character zero = '0';
    return (character == zero) ? true : false;
}

bool cli::Parser::Lexer::hasInvalidCharacter(const rawToken& token) const {
    const auto iterator = std::ranges::find_if(token, [](const auto& character) {

        return (character == '|' || character == '[' || character == ']'
                || character == '+' || character == '{' || character == '}'
                || character == '~' || character == '^');
    });

    return (iterator != token.end()) ? true : false;
}

void cli::Parser::Lexer::validateArgument(const rawToken& token) const {
    try {
        validateOption(token);
    } catch(cli::InvalidCharacter_Cerr& err) {
        throw;
    }
}

//PARSER::SYNTAX_ANALYZER CORE METHODS DEFINITONS

void cli::Parser::Syntax_analyzer::addTo(const Token& token) {
    try {
        switch(token.second) {
            case TokenType::Null: {
                throw;
                break;
            }

            case TokenType::Name: {
                addToCommand_Name(token);
                break;
            }

            case TokenType::Option: {
                addToCommand_Options(token);
                break;
            }

            case TokenType::Argument: {
                addToCommand_Arguments(token);
                break;
            }
        }
    } catch (std::runtime_error& err) {
        throw;
    }
}

const cli::Parser::Varaint cli::Parser::Syntax_analyzer::getValue(const Token& token) const{
    const auto type = getType(token);
    switch(type) {
        case VariantType::Int: {
            return std::stoi(token.first);
        }

        case VariantType::String: {
            return token.first;
        }

        case VariantType::Bool: {
            const auto string = token.first;
            return (string == "true") ? true : false;
        }
    }
}

const cli::Parser::VariantType cli::Parser::Syntax_analyzer::getType(const Token& token) const {
    if (token.first == "true" || token.first == "false") {
        return VariantType::Bool;
    }

    const auto firstCharacter = token.first[0];
    if (std::isdigit(firstCharacter)) {
        return VariantType::Int;
    }

    return VariantType::String;
}


void cli::Parser::Syntax_analyzer::addToCommand_Name(const Token& token) {
    m_CommandName +=  token.first;
}

void cli::Parser::Syntax_analyzer::addToCommand_Options(const Token& token) {
    const auto value = getValue(token);
    m_CommandOptions.insert(value);
}

void cli::Parser::Syntax_analyzer::addToCommand_Arguments(const Token& token) {
    const auto value = getValue(token);
    m_CommandArguments.insert(value);
}

cli::Parser::Syntax_analyzer::Data cli::Parser::Syntax_analyzer::getData() const {
    return {m_CommandName, m_CommandOptions, m_CommandArguments};
}
