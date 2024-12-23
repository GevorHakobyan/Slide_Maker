#pragma once
#include "Action.h"
#include "RemoveItem.h"

namespace edition {
    class AddItem : public Action {
        public:
        using ID = float;
        AddItem() = default;
        AddItem(const Info&);
        Pair create(Info&) override;
        void Do() override;
        ID getItemId() const;
        private:
        ID m_ItemId{};
    };
}; //namespace edition