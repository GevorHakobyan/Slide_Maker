#pragma once
#include "../CLI/CommandFactory/ItemInfo.h"
#include "../Include/Item.h"
#include <functional>

namespace edition {

    class ItemFactory {
        public:
        using ItemInfo = cli::ItemInfo;
        using Type = std::string;
        using Item = document::A_Item;
        using Location = document::A_Item::Location;
        using AttributePtr = document::A_Item::AttributePtr;
        using FunctionType = Item(const Location&, const AttributePtr);
        using FunctionPtr = std::function<FunctionType>;
        using ItemMap = std::unordered_map<Type, FunctionPtr>;
        using ItemPtr = std::unique_ptr<Item>;

        public:
        static  ItemPtr create(const ItemInfo&);

        private:
        ItemFactory() = default;
        ItemMap m_Items;
    };

}; //namespace edition