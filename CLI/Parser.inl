#include "Parser.h"

cli::Parser::Lexer::Lexer(Text text) 
: m_tokens{} 
{
    setTokens(text);
};

bool cli::Parser::Lexer::isLexicallyValid(Text text) const{

}

void cli::Parser::Lexer::setTokens(Text text) {
    for (const auto& tokens : text) {
        tokenize(tokens);
    }
}

void cli::Parser::Lexer::tokenize(std::string& tokens) {
    char* textArr = const_cast<char*>(tokens.c_str());
    const char* delim = " ";
    char* token = std::strtok(textArr, delim);

    while(nullptr != token) {
        m_tokens.push_back(token);
        token = std::strtok(nullptr, delim);
    }
}