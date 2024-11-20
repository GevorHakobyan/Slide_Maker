#pragma once
#include <unordered_map>
#include <variant>
#include <string>

namespace cli{
        enum class EMPTY{empty};
        using Tuple = std::tuple<float, float, float>;
        using Pair = std::pair<float, float>;
        using String = std::string;
        using argument = std::variant<Tuple, Pair, String, int, bool, float, EMPTY>;
        using C_name = std::string;
        using option = std::string;
        using C_arguments = std::unordered_map<option, argument>;
        using C_type = std::string;
}; //namespace cli