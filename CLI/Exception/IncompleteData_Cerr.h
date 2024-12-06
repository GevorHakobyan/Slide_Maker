#pragma once
#include "Exception.h"

namespace cli {
    class IncompleteData_Cerr :  public Exception {
        public:
        IncompleteData_Cerr(const Messeage&, const Location& = std::source_location::current());
    };
}; //namespace cli}