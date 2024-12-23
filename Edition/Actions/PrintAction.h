#pragma once
#include "Action.h"

namespace edition {
    class PrintAction : public Action {
        public:
        PrintAction() = default;
        PrintAction(const Info&);
        Pair create(Info&) override;
        void Do() override;
    };
}; //namespace edition