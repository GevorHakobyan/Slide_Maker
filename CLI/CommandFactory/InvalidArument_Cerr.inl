#include "InvalidArgument_Cerr.h"

cli::InvalidArgument_Cerr::InvalidArgument_Cerr(const Messeage& messeage, const InvalidArgument& argument)
: Exception{messeage}, m_invalidArgument{argument} {};

const char* cli::InvalidArgument_Cerr::what() const {
    const auto baseMesseage = Exception::what();
    const auto additionalInfo = '\n' + "Argument: " + m_invalidArgument + " not found\n";
    const auto fullMesseage = baseMesseage + additionalInfo;

    return fullMesseage.c_str();
}