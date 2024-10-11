#include "InvalidArgument_Cerr.h"

cli::InvalidArgument_Cerr::InvalidArgument_Cerr(const Messeage& messeage, const InvalidArgument& argument, const Location& loc)
: Exception{messeage, loc} {
    setInvalidArgument(argument);
    setMesseage();
};

const char* cli::InvalidArgument_Cerr::what() const noexcept {
    return m_messeage.c_str();
}

void cli::InvalidArgument_Cerr::setMesseage() {
    const auto baseMesseage = Exception::what();
    const auto additionalInfo = '\n' + "Argument: " + m_invalidArgument + " not found\n";
    m_messeage = baseMesseage + additionalInfo;
}

void cli::InvalidArgument_Cerr::setInvalidArgument(const InvalidArgument& argument) {
    m_invalidArgument = "unknown";
}