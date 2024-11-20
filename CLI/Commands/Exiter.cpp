#include "Exiter.h"

cli::Exiter::Exiter(const Arguments& arguments)
: I_Command(arguments) {};

bool cli::Exiter::Execute() {
    return false;
}

cli::I_Command::CommandPtr cli::Exiter::create(const ArgList& Function_arguments) {
    const auto arguments = Function_arguments.getArgumetns();

    try {
        validateInfo(arguments);
    } catch (const Exception& err) {
        throw;
    }
    
    return std::move(std::make_unique<cli::Exiter>(arguments));
}