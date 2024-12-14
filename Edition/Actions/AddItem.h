#pragma once
#include "Action.h"
#include "RemoveItem.h"

namespace edition {
    class AddItem : public Action {
        public:
        AddItem() = default;
        AddItem(const Info&);
        Pair create(const Info&) override;
        void Do() override;
        private:
    };
}; //namespace edition