#pragma once
#include "Command.h"

namespace cli {
    class Slide_Maker : public I_Command {
        public:
        Slide_Maker(const Options&, const Arguments&);
        void Execute() override;
        void setValidOptions();
        void setValidArguments();
    };
} //namespace cli