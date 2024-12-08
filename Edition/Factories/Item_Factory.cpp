#include "Item_Factory.h"

edition::ItemFactory::ID edition::ItemFactory::m_id;

edition::ItemFactory::ItemPtr edition::ItemFactory::create(Arguments info) {
    const auto ptr = std::make_shared<document::Attributes>(info);
    return Item::create(ptr);
}