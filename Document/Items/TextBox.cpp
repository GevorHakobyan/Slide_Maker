#include "TextBox.h"

document::TextBox::TextBox(const Location& loc, const TextBox_Attr& attr, const Text& text)
: A_Item(loc, std::make_shared<I_Attributes>(attr)), m_text{text} {};

void document::TextBox::setGeometry(const Location& location) {
    m_geometry = location;
}

void document::TextBox::setAttributes(const I_Attributes& attr) {
    //m_attributesPtr = std::make_unique<TextBox_Attr>();
}