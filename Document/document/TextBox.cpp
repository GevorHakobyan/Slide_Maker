#include "../../Include/TextBox.h"

document::TextBox::TextBox(const Location& loc, const TextBoxAttrPtr attr, const Text& text, ID id)
: A_Item{loc, attr, id}, m_text{text} {};

document::TextBox::ItemPtr document::TextBox::create(const Location location, const AttributePtr atrr) {
    ItemPtr ptr  = std::make_unique<TextBox>(location, atrr, 5);
    return std::move(ptr);    
}

