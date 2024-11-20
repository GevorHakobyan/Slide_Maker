#pragma once
#include "Attributes.h"
#include "Item.h"
#include <functional>

namespace edition {

    class ItemFactory {
        public:
        using Arguments = cli::C_arguments;
        using ID = int;
        using Type = cli::ShapeType;
        using Item = document::A_Item;
        using ItemPtr = std::unique_ptr<Item>;
        using Location = document::A_Item::Location;
        using AttributePtr = document::A_Item::AttributePtr;
        using FunctionType = ItemPtr(const Arguments&);
        using FunctionPtr = std::function<FunctionType>;
        using ItemMap = std::unordered_map<Type, FunctionPtr>;

        public:
        static  ItemPtr create(Arguments);

        private:
        ItemFactory() = default;
        static ID m_id;
        static ItemMap m_Items;
    };

}; //namespace edition