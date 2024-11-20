#pragma once
#include "Command.h"
#include "SlideInfo.h"
//#include "StoreManager.h"

namespace cli {
    class Slide_Maker : public I_Command {
        public:
        Slide_Maker() = default;
        Slide_Maker(const Arguments&);
        bool Execute() override;
        CommandPtr create(const ArgList&) override;
    };
} //namespace cli