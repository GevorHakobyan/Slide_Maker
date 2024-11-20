#pragma once
#include "Item_Factory.h"
#include "Rectangle.h"

namespace edition {
    class ItemInitializer {
        public:
        using Uptr = std::unique_ptr<document::A_Item>;
        public:
        static void Initialize();
    };
}; //namespace edition