#pragma  once
#include "Types.h"

namespace document {
    class Attributes {
        public:
        using String = std::string;
        using Content = std::string;
        using Title  =  std::string;
        using Radius = float;
        using Vertexes = std::tuple<float, float, float>;
        using Center = std::pair<float, float>;
        using Location = Center;
        using Color = cli::Color;
        using Type = cli::Type;
        using ID = size_t;
        using Key =  cli::option;
        using Value = cli::argument;
        using Map = cli::C_arguments;

        void addAttribute(const Key, const Value&);
        Color getColor() const;
        Type getType() const;
        Title getTitle() const;
        Content getContent() const;
        Radius getRadius() const;
        Center getCenter() const;
        Vertexes getVertexes() const;
        Location getLocation() const;
         ID getOwnerId() const; 
        ID getId() const; 
        protected:
        Map _attributes{};
    };
}; //namespace cli




