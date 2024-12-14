#pragma once

#include <utility>
#include <memory>
#include <mutex>
#include <iostream>
#include <sstream>
#include <ranges>
#include "CommandInfo.h"
#include "CommandCreator.h"
#include "InvalidCharacter_Cerr.h"
#include "InvalidSyntax_Cerr.h"

namespace cli {

    class Parser {
        public:
        enum class TokenType{Null = 0, Name, Option, Argument};
        enum class State{S_Start, S_Name, S_Opt, S_Arg, S_Dead, S_End};
        public: //usings
        using FactoryPtr  = std::unique_ptr<cli::CommandCreator>;
        using Variant = cli::argument;
        using Text = std::stringstream;
        using rawToken = std::string;
        using CommandPtr = std::unique_ptr<cli::I_Command>;
        using Token = std::pair<Variant, TokenType>;
        using Character = char;
        using Value = std::unordered_map<TokenType, State>;
        using StateDiagram = std::unordered_map<State, Value>;
        using ErrorType = InvalidSyntax_Cerr::Error;
        

        private: //nested classes
        class Lexer {
            public://methods
            Lexer() = default;
            ~Lexer() = default;
            Token getToken(Text&);
            private:
            Token tokenize(Text&);
            Token getRange(rawToken);
            Pair getNumbers(rawToken&);
            Token getAsNumber(rawToken);
            Token GetValidArgument(rawToken);
            rawToken getRawToken(Text&);
            void getFullArgument(Text&, rawToken&);
            //type deciders
            bool isWord(const rawToken&) const;
            bool isOption(const rawToken&) const;
            bool isArgument() const;

            //type decider helpers
            bool isLetter(const Character) const;
            bool hasDigit(const rawToken&) const;
            bool isHyphen(const Character) const;
            std::pair<bool, bool> isInScope(const rawToken&) const;
            bool isRange(const rawToken&) const;
            bool isLastQuotation(const rawToken&) const;

            //specific type validators
            void validateWord(const rawToken&) const;
            void validateOption(const rawToken&) const;
            void validateArgument(const rawToken&) const;

            //validator helpers
            bool isZeroFirst(const rawToken&) const;
            bool hasInvalidCharacter(const rawToken&) const;
            bool isZero(const Character) const;
            void removeScope(rawToken&) const;
        };

        class Syntax_analyzer {
            using Data = std::pair<C_name, C_arguments>;
            using Argument = std::pair<Token, Token>;

            public:
            Syntax_analyzer() = default;
            ~Syntax_analyzer() = default;
            void addTo(const Token&);
            Data getData() const;
            void clearCollectedData();

            private:
            void addToCommand_Name(const Token&);
            void addToCommand_Arguments(const Argument&);
            const Variant getValue(const Token&) const;

            private: //PARSED COMMAND INFO
            Argument m_argument{};
            C_name m_CommandName{};
            C_arguments m_CommandArguments{};
        };

       

        public: //methods
        Parser();
        CommandPtr getCommand(std::istream&);
        ~Parser() = default;

        private:
        CommandInfo Parse(Text&);
        void parseText(Text&);
        void setCommandName(const C_name&);
        void setCommandArguments(C_arguments&);
        void setStateDiagram();
        void setStartState();
        void setNameState();
        void setOptionState();
        void setArgumentState();
        const State pass(const Token&);
        const State getNextState(const Token&) const;
        const ErrorType getErrorType(const Token&) const noexcept;
        void restateAutomata();



        private: //data members
        CommandInfo m_ParsedCommand;
        static StateDiagram m_states;
        static State m_CurrentState;
        FactoryPtr m_CommandFactory{nullptr};
        Lexer m_lexer{};
        Syntax_analyzer m_syntaxAnalyzer{};
    };
} //namespace cli