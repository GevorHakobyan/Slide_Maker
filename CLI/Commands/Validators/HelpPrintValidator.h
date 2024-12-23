#pragma once 
#include "Validator.h"
#include "InvalidCommand_Cerr.h"

namespace cli {
    class HelpPrintValidator : public Validator {
        public:
        void Validate(const Data&) const override;
    };
};//namespace cli