#include "Exiter.h"

cli::Exiter::Exiter(const Arguments& arguments)
: I_Command(arguments) {};

bool cli::Exiter::Execute() {
    return false;
}

cli::I_Command::CommandPtr cli::Exiter::create(const Arguments& collectedArgumnets) {
    validateInfo(collectedArgumnets);
    return std::move(std::make_unique<cli::Exiter>(collectedArgumnets));
}