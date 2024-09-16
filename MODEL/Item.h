#pragma once
#include "Attributes.h"
#include "Geometry.h"
#include "Type.h"

namespace model {

    //this will be an abstract class for various items 
    //probably pure virtual
    class A_Item {
        public:
        virtual ~A_Item() = default;
        virtual const S_Type& getType() const = 0;
        virtual const S_Geometry& getGeometry() const = 0;
        virtual const I_Attributes& getAttributes() const = 0;
        private:
        S_Type m_type;
        S_Geometry m_geometry;
        I_Attributes m_attributes;
    };

} //namespace model