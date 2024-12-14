#pragma once
#include "Action.h"

namespace edition {
    class RemoveItem : public Action {
        public:
        RemoveItem() = default;
        RemoveItem(const Info&);
    };
}; //namespace edition