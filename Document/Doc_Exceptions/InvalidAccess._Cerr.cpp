#include "InvalidAccess_Cerr.h"

namespace document {
    InvalidAccess::InvalidAccess(const Messeage& messeage, const Location& loc)
    : Exception(messeage, loc) {
        setMesseage();
    }
}; //namespace document