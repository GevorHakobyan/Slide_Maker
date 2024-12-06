#include "Item_Factory.h"

edition::ItemFactory::ItemMap edition::ItemFactory::m_Items;
edition::ItemFactory::ID edition::ItemFactory::m_id;

void edition::ItemFactory::setValidItems(Name name, InstancePtr instance) {
    m_Items[name] = std::move(instance);
}

edition::ItemFactory::ItemPtr edition::ItemFactory::create(Arguments info) {
    auto typeName = std::get<std::string>((*info.find("t")).second);
    AttributePtr attr = std::make_shared<document::Attributes>(std::move(info));
    return m_Items.find(typeName)->second->create(std::move(attr));
}