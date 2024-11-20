#pragma once
#include <unordered_map>
#include <variant>
#include <string>

namespace cli{
         struct Color {
          float _red;
          float _green;
          float _blue;  
        };
        enum class ShapeType {Square = 1, Rectangle, Triangle, Circle, TextBox};
        enum class EMPTY{empty};
        using Type = ShapeType;
        using Tuple = std::tuple<float, float, float>;
        using Pair = std::pair<float, float>;
        using String = std::string;
        using argument = std::variant<Tuple, Pair, String, size_t, bool, float, Color, Type, EMPTY>;
        using C_name = std::string;
        using option = std::string;
        using C_arguments = std::unordered_map<option, argument>;
        using C_type = std::string;
}; //namespace cli