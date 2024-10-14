#include "Item.h"

document::A_Item::A_Item() 
: m_attributesPtr{nullptr} {
    m_geometry = std::move(std::make_pair(5, 5));
}

document::A_Item::A_Item(const Location& location)
: m_geometry{location}, m_attributesPtr{nullptr} {}

document::A_Item::Location&& document::A_Item::getGeometry(){
    return std::move(m_geometry);
}

document::A_Item::AttributePtr document::A_Item::getAttributesPtr() {
    return std::move(m_attributesPtr);
}

document::A_Item::A_Item(A_Item&& rhs)
: A_Item(rhs.getGeometry()) {
    this->m_attributesPtr = getAttributesPtr();
}

bool document::operator==(const A_Item& first, const A_Item& second) {
    return (first.m_attributesPtr == second.m_attributesPtr) ? true : false;
}

document::A_Item& document::A_Item::operator=(A_Item&& rhs) {
    if (*this == rhs) {
        return *this;
    }

    this->m_attributesPtr.release();
    this->m_attributesPtr = rhs.getAttributesPtr();
    this->m_geometry = rhs.getGeometry();
    return *this;
}