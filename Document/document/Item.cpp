#include "Item.h"


document::A_Item::A_Item(const BoundingBoxPtr boundingBox, AttributePtr atrbutes, const ID id)
: m_BoundingBox{boundingBox}, m_attributesPtr{atrbutes}, m_id{id} {}

document::A_Item::Location document::A_Item::getGeometry(){
    return m_BoundingBox->getLocation();
}

document::A_Item::AttributePtr document::A_Item::getAttributesPtr() {
    return m_attributesPtr;
}

document::A_Item::BoundingBoxPtr document::A_Item::getBoundingBox() {
    return m_BoundingBox;
}

document::A_Item::ID document::A_Item::getId() const {
    return m_id;
}

document::A_Item::A_Item(A_Item&& rhs) noexcept
: A_Item(rhs.getBoundingBox(), rhs.getAttributesPtr(), rhs.getId()) {}

bool document::operator==(const A_Item& first, const A_Item& second) noexcept {
    return (first.m_attributesPtr == second.m_attributesPtr) ? true : false;
}

document::A_Item& document::A_Item::operator=(A_Item&& rhs) noexcept {
    if (*this == rhs) {
        return *this;
    }

    this->m_attributesPtr = rhs.getAttributesPtr();
    this->m_BoundingBox = rhs.getBoundingBox();
    return *this;
}

void document::A_Item::move(const Location& newLocation) {
    m_BoundingBox->moveObject(newLocation);
}

