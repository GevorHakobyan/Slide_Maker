#include "InvalidCommand_Cerr.h"

cli::InvalidCommand_Cerr::InvalidCommand_Cerr(const Messeage& messeage, const CommandName& name, const Location& loc)
: Exception(messeage, loc), m_invalidCommand{name} {
    setMesseage();
};

const char* cli::InvalidCommand_Cerr::what() const noexcept
{

    return m_messeage.c_str();
}

void cli::InvalidCommand_Cerr::setMesseage() {
    const auto baseMesseage = Exception::what();
    const auto additionalMesseage = '\n' + "Command: " + m_invalidCommand + " Not Found\n";
    m_messeage = baseMesseage;
}