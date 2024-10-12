#pragma once
#include "I_Attributes.h"
#include <utility>

namespace document {

    class A_Item {
        public:
        using Location = std::pair<float, float>;

        public:
        virtual ~A_Item() = default;
        virtual void setGeometry(const Location&) = 0;
        virtual void setAttributes(const I_Attributes&) = 0;

        protected:
        Location m_geometry;
        I_Attributes m_attributes;
    };

} //namespace document