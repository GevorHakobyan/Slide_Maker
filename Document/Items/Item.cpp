#include "Item.h"


document::A_Item::A_Item(const Location& location, AttributePtr atrbutes)
: m_geometry{location}, m_attributesPtr{atrbutes} {}

document::A_Item::Location&& document::A_Item::getGeometry(){
    return std::move(m_geometry);
}

document::A_Item::AttributePtr document::A_Item::getAttributesPtr() {
    return m_attributesPtr;
}

document::A_Item::A_Item(A_Item&& rhs) noexcept
: A_Item(rhs.getGeometry(), rhs.getAttributesPtr()) {}

bool document::operator==(const A_Item& first, const A_Item& second) noexcept {
    return (first.m_attributesPtr == second.m_attributesPtr) ? true : false;
}

document::A_Item& document::A_Item::operator=(A_Item&& rhs) noexcept {
    if (*this == rhs) {
        return *this;
    }

    this->m_attributesPtr = rhs.getAttributesPtr();
    this->m_geometry = rhs.getGeometry();
    return *this;
}

