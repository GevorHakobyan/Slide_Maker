#include "Exiter.h"

cli::Exiter::Exiter(const Options& options, const Arguments& arguments)
: I_Command(options, arguments) {};

bool cli::Exiter::Execute() {
    return false;
}

cli::I_Command::CommandPtr cli::Exiter::create(const ArgList& Function_arguments) {
    const auto arguments = Function_arguments.getArgumetns();
    const auto options = Function_arguments.getOptions();

    try {
        validateInfo(options, arguments);
    } catch (const Exception& err) {
        throw;
    }
    
    return std::move(std::make_unique<cli::Exiter>(options, arguments));
}