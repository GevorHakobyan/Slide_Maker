#include "Item.h"
document::Item::Map document::Item::m_BoundingBox_Creators{};

document::Item::Item(AttributePtr attrs)
: m_BoundingBox{nullptr},  m_Attributes{std::move(attrs)} {
    setBoundingBox();
}

document::Item::ItemPtr document::Item::create(AttributePtr attr) {
    m_BoundingBox_Creators["crc"] = Bounding_Box::CR_BoundingBox;
    m_BoundingBox_Creators["rec"] = Bounding_Box::RC_BoundingBox;
    m_BoundingBox_Creators["trg"] = Bounding_Box::TR_BoundingBox;
    m_BoundingBox_Creators["tb"] = Bounding_Box::RC_BoundingBox;
    return std::move(std::make_unique<Item>(attr));
}

void document::Item::setBoundingBox() {
    const auto type = m_Attributes->getType();
    const auto creator = m_BoundingBox_Creators[type];
    m_BoundingBox = creator(m_Attributes);
}

const document::Item::AttributePtr document::Item::getAttributes() const {
    return m_Attributes;
}

const document::Item::BoundingBoxPtr document::Item::getBoundingBox() const {
    return m_BoundingBox;
}

document::Item::Item(Item&& rhs) noexcept
: Item(rhs.getAttributes()) {}

bool document::operator==(const Item& first, const Item& second) noexcept {
    return (first.getId() == second.getId()) ? true : false;
}

document::Item& document::Item::operator=(Item&& rhs) noexcept {
    if (*this == rhs) {
        return *this;
    }

    this->m_BoundingBox = rhs.getBoundingBox();
    this->m_Attributes = rhs.getAttributes();
    return *this;
}

void document::Item::move(const Location& newLocation) {
    m_BoundingBox->moveObject(newLocation);
}

document::Item::ID document::Item::getId() const {
    return m_Attributes->getId();
}
