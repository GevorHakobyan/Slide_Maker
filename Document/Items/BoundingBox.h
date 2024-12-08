#pragma once
#include <utility>
#include "Attributes.h"
#include <memory>

namespace document {

    class Bounding_Box {
        public:
        using Pair = std::pair<float, float>;
        using AttributePtr = std::shared_ptr<Attributes>;
        using thisPtr = std::unique_ptr<Bounding_Box>;

        public:
        Bounding_Box() = default;
        Pair getCurrentPostion() const;
        float getLength() const;
        float getWidth() const;
        void moveObject(Pair);
        static thisPtr CR_BoundingBox(const AttributePtr); //for Triangle
        static thisPtr TR_BoundingBox(const AttributePtr); //for Circle
        static thisPtr RC_BoundingBox(const AttributePtr); //for Rectangle 

        private:
        void setOrigin(Pair);
        void setLength(float);
        void setWidth(float);
        void setCurrentPostion(Pair);
        
        private:
        Pair m_Origin{0.0, 0.0};
        Pair m_CurrentPosition{};
        float m_Length{};
        float m_Width{};
    };
};