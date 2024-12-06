#include "Rectangle.h"

namespace document {
    Rectangle::Rectangle(AttributePtr attributes) 
    : A_Item{std::move(attributes)} {};

    Rectangle::ItemPtr Rectangle::create(AttributePtr attributes) {
        return std::move(std::make_unique<Rectangle>(attributes));
    }
    
    void Rectangle::setBoundingBox() {
        const auto location = m_Attributes->getLocation();
        const auto length = m_Attributes->getLength();
        const auto width = m_Attributes->getWidth();

        m_BoundingBox = std::make_shared<Bounding_Box>();
        m_BoundingBox->setOrigin(location);
        m_BoundingBox->setLength(length);
        m_BoundingBox->setWidth(width);
    }
}; //namespace document