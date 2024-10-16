#pragma once
#include "Item.h"
#include "TextBox_Attr.h"
#include <string>

namespace document {
    class TextBox : public A_Item {
       public:
       using  Text = std::string;

       public:
       TextBox(const Location&, const TextBox_Attr&, const Text&);
       ~TextBox() = default;
       void setGeometry(const Location&) override;
       void setAttributes(const I_Attributes&) override;

       private:
       Text m_text{};
    };
}; //document