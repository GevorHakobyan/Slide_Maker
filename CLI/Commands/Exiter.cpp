#include "Exiter.h"
cli::I_Command::Arguments cli::Exiter::m_Valid_Info{};

cli::Exiter::Exiter(const Arguments& arguments)
: I_Command(arguments) {};

bool cli::Exiter::Execute() {
    return false;
}

cli::I_Command::CommandPtr cli::Exiter::create(const Arguments& collectedArgumnets) {
    validateInfo(collectedArgumnets, m_Valid_Info);
    return std::move(std::make_unique<cli::Exiter>(collectedArgumnets));
}

void cli::Exiter::addValue(const cli::option opt, const cli::argument arg) {
    m_Valid_Info[opt] = arg;
} 