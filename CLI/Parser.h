#pragma once
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <optional>
#include <unordered_set>
#include <unordered_map>

namespace cli {

    class Parser {
        public: //usings
        using C_name = std::string_view;
        using Text = std::string_view;
        using C_arguments = std::unordered_set<std::string_view>;
        using C_options = std::unordered_set<std::string_view>;
        using CommandInfo = std::tuple<C_name, C_arguments, C_options>;
        using Key = C_name;
        using Value = std::pair<std::optional<C_arguments>, std::optional<C_options>>;
        using CommandList = std::unordered_map<Key, Value>;
        using parserPtr = std::shared_ptr<Parser>;

        private: //nested classes
        class Lexer {
            public:
            using Token = char*;
            using Text = std::initializer_list<std::string&>;
            using Tokens = std::vector<Token>;

            public://methods
            Lexer(Text);
            ~Lexer() = default;
            bool isLexicallyValid(Text) const;
            private:
            void tokenize(std::string&);
            void setTokens(Text);
            bool isTokenValid(Token) const;

            private://members
            Tokens m_tokens;
        };

        class Syntax_analyzer {
            using Text = std::string_view;
            public:
            Syntax_analyzer() = default;
            ~Syntax_analyzer() = default;
            bool isSyntaticallyValid(Text) const;
        };

        /*class Semantic_analyzer { // I am not sure about this class
                                    // do I really need it
                                    //what does it mean in this case
                                    //the way I check the syntax is enough
        };*/
        
       
        public: //methods
        static parserPtr getInstance();
        Parser(const Parser&) = delete;
        Parser& operator=(const Parser&) = delete;
        CommandInfo operator()(Text);

        private:
        Parser() = default;
        ~Parser() = default;
        CommandInfo parseText(Text);

        private: //data members
        static parserPtr m_ptr;
        CommandList m_list;
    };
    #include "Parser.inl"
} //namespace cli