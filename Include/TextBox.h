#pragma once
#include "Item.h"
#include "TextBox_Attr.h"
#include <string>

namespace document {
    class TextBox : public A_Item {
       public:
       using  Text = std::string;
       using ID = size_t;
       using TextBoxAttrPtr = std::shared_ptr<TextBox_Attr>;

       public:
       TextBox(const Location&, const TextBoxAttrPtr, const Text&, ID);
       ~TextBox() = default;

       ItemPtr create(const Location, const AttributePtr) override;
       private:
       Text m_text{};
    };
}; //document