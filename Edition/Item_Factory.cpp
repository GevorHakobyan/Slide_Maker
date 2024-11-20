#include "Item_Factory.h"

edition::ItemFactory::ItemMap edition::ItemFactory::m_Items;
edition::ItemFactory::ID edition::ItemFactory::m_id;

edition::ItemFactory::ItemPtr edition::ItemFactory::create(const ItemInfo& info) {
    const auto type = info.getType();
    auto funcPtr = m_Items[type];
    ++m_id;

    return std::move(funcPtr(info, m_id));
}