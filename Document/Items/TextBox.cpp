#include "TextBox.h"

document::TextBox::TextBox(const Location& loc, const TextBoxAttrPtr attr)
: A_Item{loc, attr} {};

document::TextBox::ItemPtr document::TextBox::create(ItemInfoPtr info, const ID id) {
    const auto color = info->getColor();
    const auto width =  info->getWidth();
    const auto length = info->getLength();
    const auto content = (*dynamic_pointer_cast<TextBoxInfoPtr>(info))->getContent();
    auto atrr = std::make_shared<TextBox_Attr>(color, 0, content);

    const auto location = std::make_pair<float, float>(5.0, 2.3);
    ItemPtr ptr  = std::make_unique<TextBox>(location, atrr);
    return std::move(ptr);    
}

