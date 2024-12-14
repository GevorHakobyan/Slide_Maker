#pragma once
#include "Action.h"
#include "RemoveSlide.h"

namespace edition {
    class AddSlide : public Action {
        public:
        Actions create(Info) override;
        void Do() override;
    };
}; //namespace edition