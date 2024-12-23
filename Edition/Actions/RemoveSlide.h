#pragma once
#include "Action.h"

namespace edition {
    class RemoveSlide : public Action {
        public:
        RemoveSlide() = default;
        RemoveSlide(const Info&);
        Pair create(Info&) override;
        void Do() override;
    };
}