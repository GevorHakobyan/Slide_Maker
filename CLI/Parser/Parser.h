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
        enum class VariantType{Int, String, Bool};
        public: //usings
        using FactoryPtr  = std::unique_ptr<cli::CommandCreator>;
        using Varaint = std::variant<int, std::string, bool>;
        using Text = std::stringstream;
        using rawToken = std::string;
        using CommandPtr = std::unique_ptr<cli::I_Command>;
        using Token = std::pair<std::string, TokenType>;
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
            rawToken getRawToken(Text&);
            //type deciders
            bool isWord(const rawToken&) const;
            bool isOption(const rawToken&) const;
            bool isArgument(const rawToken&) const;

            //type decider helpers
            bool isLetter(const Character) const;
            bool hasDigit(const rawToken&) const;
            bool isHyphen(const Character) const;
            bool isInQuotation(const rawToken&) const;

            //specific type validators
            void validateWord(const rawToken&) const;
            void validateOption(const rawToken&) const;
            void validateArgument(const rawToken&) const;

            //validator helpers
            bool isZeroFirst(const rawToken&) const;
            bool hasInvalidCharacter(const rawToken&) const;
            bool isZero(const Character) const;
        };

        class Syntax_analyzer {
            using Data = std::tuple<C_name, C_arguments, C_options>;

            public:
            Syntax_analyzer() = default;
            ~Syntax_analyzer() = default;
            void addTo(const Token&);
            Data getData() const;

            private:
            void addToCommand_Name(const Token&);
            void addToCommand_Options(const Token&);
            void addToCommand_Arguments(const Token&);
            const Varaint getValue(const Token&) const;
            const VariantType getType(const Token&) const;

            private: //PARSED COMMAND INFO
            C_name m_CommandName{};
            C_options m_CommandOptions{};
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
        void setCommandOptions(const C_options&);
        void setCommandArguments(const C_arguments&);
        void setStateDiagram();
        void setStartState();
        void setNameState();
        void setOptionState();
        void setArgumentState();
        const State pass(const Token&);
        const State getNextState(const Token&) const;
        const ErrorType getErrorType(const Token&) const noexcept;



        private: //data members
        CommandInfo m_ParsedCommand;
        static StateDiagram m_states;
        static State m_CurrentState;
        FactoryPtr m_CommandFactory{nullptr};
        Lexer m_lexer{};
        Syntax_analyzer m_syntaxAnalyzer{};
    };
} //namespace cli