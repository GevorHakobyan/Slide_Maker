#pragma once
#include "Item.h"

namespace document {
    class TextBox : public A_Item {
        public:
        TextBox() = default;
        TextBox(AttributePtr);
        ItemPtr create(AttributePtr) override;
        void setBoundingBox() override;
    };
}; //namespace document