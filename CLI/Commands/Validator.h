#pragma once
#include "Types.h"
#include "InvalidOption_Cerr.h"
#include "InvalidArgument_Cerr.h"

namespace cli {
    class Validator {
        public:
        using Data = cli::C_arguments;
        public:
        virtual void Validate(const Data&) const = 0;
    };
}; //namespace cli