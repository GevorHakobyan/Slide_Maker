#pragma once 
#include "Exception.h"

namespace document {
    class InvalidAccess : public cli::Exception {
        public:
        InvalidAccess(const Messeage&, const Location& = std::source_location::current());
    };
}; //namespace document