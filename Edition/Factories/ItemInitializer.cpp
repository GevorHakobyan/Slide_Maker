#include "ItemInitializer.h"

namespace edition {
    void ItemInitializer::Initialize() {
        Uptr ptr = std::make_unique<document::Rectangle>();
        ItemFactory::setValidItems("rec", std::move(ptr));
    }
}; //namespace edition