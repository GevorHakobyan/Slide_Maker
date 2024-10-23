#pragma once
#include "Item.h"

namespace document {

    class Bounding_Box {
        public:
        using Minimum = std::pair<float, float>;
        using Maximum = std::pair<float, float>;
        using Cooridnate = std::pair<Minimum, Maximum>;
        using Origin = A_Item::Location;
        using Location = A_Item::Location;
        using Length = I_Attributes::Length;
        using Width = I_Attributes::Width;

        public:
        Bounding_Box(const Origin&, const Length&, const Width);
        Origin getLocation() const;
        void moveObject(const Location&);

        private:
        void setCoordinates(const Length&, const Width&);
        void setOrigin(const Origin&);

        private:
        Origin m_Origin{0.0, 0.0};
        Cooridnate m_Coordinates{};
    };
};