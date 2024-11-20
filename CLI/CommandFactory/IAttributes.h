#pragma  once
#include <unordered_map>
#include <variant>
#include <string>
#include <optional>

namespace document {
    struct IAttributes {
        public:
         struct Colors {
          float _red;
          float _green;
          float _blue;  
        };
        enum class ShapeType {Square = 1, Rectangle, Triangle, Circle, TextBox};
        using String = std::string;
        using Color = Colors;
        using Content = std::string;
        using Title  =  std::string;
        using Type = ShapeType;
        using Radius = double;
        using Vertexes = std::tuple<float, float, float>;
        using Center = std::pair<float, float>;
        using Location = Center;
        using Length = float;
        using Width = float;
        using Key = std::string;
        using Value = std::variant<Color, std::string, ShapeType, double, Vertexes, Center, float>;
        using Map = std::unordered_map<Key, Value>;

        virtual void addAttribute(const Key, const Value&) = 0;
        virtual Color getColor() const = 0;
        virtual Type getType() const = 0;
        virtual Title getTitle() const  = 0;
        virtual Content getContent() const = 0;
        virtual Radius getRadius() const = 0;
        virtual Center getCenter() const = 0;
        virtual Length getLength() const = 0;
        virtual Width getWidth() const = 0;
        virtual Vertexes getVertexes() const = 0;
        virtual Location getLocation() const = 0;
        virtual ~IAttributes() = default;
        protected:
        Map _attributes{};
    };
}; //namespace docuent




