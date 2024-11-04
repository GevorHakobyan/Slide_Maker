#include "../Include/Item_Factory.h"

edition::ItemFactory::ItemMap edition::ItemFactory::m_Items;

edition::ItemFactory::ItemPtr edition::ItemFactory::create(const ItemInfo& info) {
    const auto type = info.getType();
    auto funcPtr = m_Items[type];

    return std::move(funcPtr(info));
}