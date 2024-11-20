#pragma once
#include "Command.h"

namespace cli {
    class Exiter : public I_Command {
        public:
        Exiter() = default;
        Exiter(const Arguments&);
        bool Execute() override;
        CommandPtr create(const ArgList&) override;
    };
}; //namespace cli