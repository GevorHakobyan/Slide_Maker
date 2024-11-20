#pragma once

#include <unordered_set>
#include <variant>
#include <string>

namespace cli{
        enum class EMPTY{empty};
        //enum class ItemType{Rectangle = 1, Triangle, Circle, Box};
        using C_name = std::string;
        using argument = std::variant<int, std::string, bool,  EMPTY>;
        using option = std::variant<int, std::string, bool, EMPTY>;
        using C_arguments = std::unordered_set<argument>;
        using C_options = std::unordered_set<option>;
        using C_type = std::string;
}; //namespace cli