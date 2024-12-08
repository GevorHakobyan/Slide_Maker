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
        using Item = document::Item;
        using ItemPtr = std::unique_ptr<Item>;

        public:
        static  ItemPtr create(Arguments);

        private:
        ItemFactory() = default;
        static ID m_id;
    };

}; //namespace edition