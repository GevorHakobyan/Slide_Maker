#pragma once
#include <string>
#include <utility>
#include <memory>
#include <mutex>
#include <iostream>
#include <ranges>
#include <unordered_set>

namespace cli {

    class Parser {
        public:
        enum class TokenType{Null = 0, Name, Option, Argument};
        public: //usings
        using Text = std::istream;
        using rawToken = std::string;
        using C_name = std::string;
        using C_arguments = std::unordered_set<std::string>;
        using C_options = std::unordered_set<std::string>;
        using Token = std::pair<std::string, TokenType>;
        using parserPtr = std::shared_ptr<Parser>;
        using Character = char;
        

        private: //nested classes
        class Lexer {
            public:
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
            void analyze(const Token&);
            Data getData() const;

            private:
            void addToCommand_Name(const Token&);
            void addToCommand_Options(const Token&);
            void addToCommand_Arguments(const Token&);
            bool hadBeenCalled(const bool) const;

            private:
            bool m_nameSetter{false};
            bool m_optionSetter{false};
            bool m_argumentSetter{false};
            private: //PARSED COMMAND INFO
            C_name m_CommandName{};
            C_options m_CommandOptions{};
            C_arguments m_CommandArguments{};
        };

        public: //available for CommandCreator
        struct CommandInfo {
            using Info = std::tuple<C_name, C_options, C_arguments>;
            C_name m_name{};
            C_options m_options{};
            C_arguments m_arguments{};
            Info getInfo() const;
        };

        public: //methods
        static parserPtr getInstance();
        Parser(const Parser&) = delete;
        Parser& operator=(const Parser&) = delete;
        CommandInfo operator()(Text&);
        ~Parser() = default;

        private:
        Parser();
        void parseText(Text&);
        void setCommandName(const C_name&);
        void setCommandOptions(const C_options&);
        void setCommandArguments(const C_arguments&);

        private: //data members
        CommandInfo m_ParsedCommand;
        static parserPtr m_ptr;
        static std::mutex m_mutex;
        Lexer m_lexer{};
        Syntax_analyzer m_syntaxAnalyzer{};
    };
    #include "Parser.inl"
} //namespace cli