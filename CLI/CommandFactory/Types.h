#pragma once

#include <unordered_set>
#include <variant>
#include <string>

namespace cli{
        enum class EMPTY{empty};
        using C_name = std::string;
        using argument = std::variant<int, std::string, bool, size_t, EMPTY>;
        using option = std::variant<int, std::string, bool, size_t,  EMPTY>;
        using C_arguments = std::unordered_set<argument>;
        using C_options = std::unordered_set<option>;
}; //namespace cli