#pragma once
#include "Action.h"

namespace edition {
    class RemoveItem : public Action {
        public:
        using ItemPtr = std::shared_ptr<document::Item>;
        public:
        RemoveItem() = default;
        RemoveItem(const Info&);
        Pair create(const Info&) override;
        void Do() override;
        private:
        ItemPtr isItemIdValid(SlidePtr, size_t) const;
    };
}; //namespace edition