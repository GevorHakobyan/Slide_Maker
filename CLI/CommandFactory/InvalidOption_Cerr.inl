#pragma once
#include "InvalidOption_Cerr.h"

cli::InvalidOption_Cerr::InvalidOption_Cerr(const Messeage& messeage, const OptionName& name)
: Exception(messeage), m_invalidOption{name} {};

const char* cli::InvalidOption_Cerr::what() const {
    const auto baseMesseage = Exception::what();
    const auto additional = '\n' + "Option: " + m_invalidOption + " not found\n";
    const auto fullMesseage = baseMesseage + additional;
    return fullMesseage.c_str();
}
