#pragma once
#include "Item.h"

namespace document {
    class Rectangle : public A_Item {
        public:
        Rectangle(AttributePtr);
        ItemPtr create(AttributePtr atributes) override;
    };
}; //namespace document