#pragma once
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <optional>

namespace cli {

    class Parser {
        public: //usings
        using C_name = std::string_view;
        using C_arguments = std::vector<std::string_view>;
        using C_options = std::vector<std::string_view>;
        using Command = std::tuple<C_name, C_arguments, C_options>;
        using Key = C_name;
        using Value = std::pair<std::optional<C_arguments>, std::optional<C_options>>;
        using CommandList = std::map<Key, Value>;
        using parserPtr = std::shared_ptr<Parser>;

        public: //methods
        static parserPtr getInstance();
        Parser(const Parser&) = delete;
        Parser& operator=(const Parser&) = delete;
        Command operator()(std::string_view);

        private:
        Parser() = default;
        ~Parser() = default;
        Command parseText(std::string_view);

        private: //data members
        static parserPtr m_ptr;
        CommandList m_list;
    };
} //namespace cli