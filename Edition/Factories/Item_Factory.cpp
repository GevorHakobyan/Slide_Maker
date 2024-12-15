#include "Item_Factory.h"

edition::ItemFactory::ID edition::ItemFactory::m_id{0};

edition::ItemFactory::ItemPtr edition::ItemFactory::create(Arguments info) {
    ++m_id;
    info["id"] = m_id;
    const auto ptr = std::make_shared<document::Attributes>(info);
    return Item::create(ptr);
}