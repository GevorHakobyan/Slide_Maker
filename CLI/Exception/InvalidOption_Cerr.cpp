#include "InvalidOption_Cerr.h"

cli::InvalidOption_Cerr::InvalidOption_Cerr(const Messeage& messeage, const InvalidOption& name, const Location& loc)
: Exception(messeage, loc) {
    setInvalidOption(name);
    setMesseage();
};

const char* cli::InvalidOption_Cerr::what() const noexcept{
    return m_messeage.c_str();
}

void cli::InvalidOption_Cerr::setMesseage() {
    const auto baseMesseage = Exception::what();
    const auto additional = '\n' + "Option: " + m_invalidOption + " not found\n";
    m_messeage = baseMesseage;
}

void cli::InvalidOption_Cerr::setInvalidOption(const InvalidOption& opt) {
    m_invalidOption = "unknown";
}