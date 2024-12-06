#include "IncompleteData_Cerr.h"

namespace cli {
    IncompleteData_Cerr::IncompleteData_Cerr(const Messeage& messeage, const Location& location)
    : Exception{messeage, location} {};
}; //namespace cli