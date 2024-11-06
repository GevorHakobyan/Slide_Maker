#pragma once
#include "Item.h"
#include "TextBox_Attr.h"
#include "TextBoxInfo.h"
#include <string>

namespace document {
    class TextBox : public A_Item {
       public:
       using TextBoxAttrPtr = std::shared_ptr<TextBox_Attr>;
       using ItemInfoPtr = std::shared_ptr<cli::ItemInfo>;
       using TextBoxInfoPtr = std::shared_ptr<cli::TextBoxInfo>;

       public:
       TextBox(const Location&, const TextBoxAttrPtr);
       ~TextBox() = default;
       ItemPtr create(ItemInfoPtr, const ID) override;
    };
}; //document