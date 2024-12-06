#pragma  once
#include "Types.h"
#include "InvalidAccess_Cerr.h"

namespace document {
    class Attributes {
        public:
        using String = std::string;
        using Pair = std::pair<float, float>;
        using Tuple = std::tuple<Pair, Pair, Pair>;
        using Location = std::pair<float, float>;
        using Length = float;
        using Width = float;
        using Color = cli::Color;
        using Type = cli::Type;
        using ID = size_t;
        using Key =  cli::option;
        using Value = cli::argument;
        using Map = cli::C_arguments;

        Attributes(Map);
        void addAttribute(const Key, const Value&);
        Color getColor() const;
        Type getType() const;
        String getTitle() const;
        String getContent() const;
        float getRadius() const;
        Pair getCenter() const;
        Tuple getVertexes() const;
        Location getLocation();
        Length getLength();
        Width getWidth();
        ID getOwnerId() const; 
        ID getId() const; 
        protected:
        Map _attributes{};
    };
}; //namespace cli




