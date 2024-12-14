#pragma once
#include "Action.h"
#include "RemoveSlide.h"

namespace edition {
    class AddSlide : public Action {
        public:
        AddSlide() = default;
        AddSlide(const Info&);
        Pair create(const Info&) override;
        void Do() override;
    };
}; //namespace edition