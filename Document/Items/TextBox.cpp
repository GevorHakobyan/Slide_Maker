#include "TextBox.h"

namespace document {
    TextBox::TextBox(AttributePtr attrPtr)
    : A_Item(std::move(attrPtr)) {};

    TextBox::ItemPtr TextBox::create(AttributePtr attrPtr) {
        return std::move(std::make_unique<TextBox>(attrPtr));
    }

    void TextBox::setBoundingBox() {
        const auto location = m_Attributes->getLocation();
        m_BoundingBox->setOrigin(location);
    }

}; //namespace document