#pragma once
#include <utility>

namespace document {

    class Bounding_Box {
        public:
        using Origin = std::pair<float, float>;
        using Location = std::pair<float, float>;
        using Length = float;
        using Width = float;

        public:
        Bounding_Box() = default;
        Location getCurrentPostion() const;
        Length getLength() const;
        Width getWidth() const;
        void moveObject(Location);

        public:
        void setCurrentPostion(Location);
        void setOrigin(Origin);
        void setLength(Length);
        void setWidth(Width);

        private:
        Origin m_Origin{0.0, 0.0};
        Location m_CurrentPosition{};
        Length m_Length{};
        Width m_Width{};
    };
};