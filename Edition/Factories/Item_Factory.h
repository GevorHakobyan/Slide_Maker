#pragma once
#include "Attributes.h"
#include "Item.h"
#include <functional>

namespace edition {

    class ItemFactory {
        public:
        using Arguments = cli::C_arguments;
        using ID = size_t;
        using Name = std::string;
        using Item = document::A_Item;
        using ItemPtr = std::unique_ptr<Item>;
        using Location = document::A_Item::Location;
        using AttributePtr = document::A_Item::AttributePtr;
        using InstancePtr = std::unique_ptr<document::A_Item>;
        using ItemMap = std::unordered_map<Name, InstancePtr>;

        public:
        static  ItemPtr create(Arguments);
        static void setValidItems(Name, InstancePtr);

        private:
        ItemFactory() = default;
        static ID m_id;
        static ItemMap m_Items;
    };

}; //namespace edition