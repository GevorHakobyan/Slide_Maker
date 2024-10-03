#include "InvalidCommand_Cerr.h"

cli::InvalidCommand_Cerr::InvalidCommand_Cerr(const Messeage& messeage, const CommandName& name)
: Exception(messeage), m_invalidCommand{name} {};

const char* cli::InvalidCommand_Cerr::what() const noexcept
{
    const auto baseMesseage = Exception::what();
    const auto additionalMesseage = '\n' + "Command: " + m_invalidCommand + " Not Found\n";
    const auto fullMesseage = baseMesseage + additionalMesseage;

    return fullMesseage.c_str();
}