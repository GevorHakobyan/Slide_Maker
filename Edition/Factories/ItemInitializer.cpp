#include "ItemInitializer.h"

namespace edition {
    void ItemInitializer::Initialize() {
        Uptr ptr1 = std::make_unique<document::Rectangle>();
        ItemFactory::setValidItems("rec", std::move(ptr1));
        
        Uptr ptr2 = std::make_unique<document::TextBox>();
        ItemFactory::setValidItems("tb", std::move(ptr2));
    }
}; //namespace edition