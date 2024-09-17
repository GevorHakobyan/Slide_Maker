#pragma once
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
        using text = std::string_view;
        using C_arguments = std::unordered_set<std::string_view>;
        using C_options = std::unordered_set<std::string_view>;
        using Command = std::tuple<C_name, C_arguments, C_options>;
        using Key = C_name;
        using Value = std::pair<std::optional<C_arguments>, std::optional<C_options>>;
        using CommandList = std::unordered_map<Key, Value>;
        using parserPtr = std::shared_ptr<Parser>;

        private: //nested classes
        class Lexer {
            public:
            using token = std::string_view;
            using text = std::initializer_list<std::string_view>;
            using validTokens = std::unordered_set<std::string_view>;
            public:
            Lexer(const validTokens&);
            ~Lexer() = default;
            bool isLexicallyValid(text) const;
            public:
            validTokens m_tokens;
        };

        class Syntax_analyzer {
            using text = std::string_view;
            public:
            Syntax_analyzer() = default;
            ~Syntax_analyzer() = default;
            bool isSyntaticallyValid(text) const;
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
        Command operator()(text);

        private:
        Parser() = default;
        ~Parser() = default;
        Command parseText(text);

        private: //data members
        static parserPtr m_ptr;
        CommandList m_list;
    };
} //namespace cli