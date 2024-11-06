#pragma once
#include "ItemInfo.h"
#include "../Include/Item.h"
#include <functional>
#include "ItemTypes.h"

namespace edition {

    class ItemFactory {
        public:
        using ItemInfo = cli::ItemInfo;
        using Type = ItemType;
        using Item = document::A_Item;
        using ItemPtr = std::unique_ptr<Item>;
        using Location = document::A_Item::Location;
        using AttributePtr = document::A_Item::AttributePtr;
        using FunctionType = ItemPtr(const ItemInfo&);
        using FunctionPtr = std::function<FunctionType>;
        using ItemMap = std::unordered_map<Type, FunctionPtr>;

        public:
        static  ItemPtr create(const ItemInfo&);

        private:
        ItemFactory() = default;
        static ItemMap m_Items;
    };

}; //namespace edition