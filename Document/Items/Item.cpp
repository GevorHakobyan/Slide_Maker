#include "Item.h"

document::A_Item::A_Item(const Location& location, const AttributePtr attrs)
: m_BoundingBox{nullptr},  m_Attributes{attrs} {
    setGeometry(location);
}

void document::A_Item::setGeometry(const Location& location) {
    m_BoundingBox = std::make_shared<Bounding_Box>(location, 5.5, 6.2);
}

document::A_Item::Location document::A_Item::getGeometry() const {
    return m_BoundingBox->getCurrentPostion();
}

const document::A_Item::BoundingBoxPtr document::A_Item::getBoundingBox() const {
    return m_BoundingBox;
}

const document::A_Item::AttributePtr document::A_Item::getAttributes() const {
    return m_Attributes;
}


document::A_Item::A_Item(A_Item&& rhs) noexcept
: A_Item(rhs.getGeometry(), rhs.getAttributes()) {}

bool document::operator==(const A_Item& first, const A_Item& second) noexcept {
    return (first.getId() == second.getId()) ? true : false;
}

document::A_Item& document::A_Item::operator=(A_Item&& rhs) noexcept {
    if (*this == rhs) {
        return *this;
    }

    this->m_BoundingBox = rhs.getBoundingBox();
    return *this;
}

void document::A_Item::move(const Location& newLocation) {
    m_BoundingBox->moveObject(newLocation);
}

document::A_Item::ID document::A_Item::getId() const {
    return m_Attributes->getId();
}
