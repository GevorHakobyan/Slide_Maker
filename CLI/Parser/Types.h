#pragma once

#include <unordered_set>
#include <variant>
#include <string>

namespace cli{
        using C_name = std::string;
        using argument = std::variant<int, std::string, bool>;
        using option = std::variant<int, std::string, bool>;
        using C_arguments = std::unordered_set<argument>;
        using C_options = std::unordered_set<option>;
}; //namespace cli