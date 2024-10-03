#include "Command.h"

cli::I_Command::Options cli::I_Command::m_Valid_Options;
cli::I_Command::Arguments cli::I_Command::m_Valid_Arguments;

cli::I_Command::I_Command(const Options& options, const Arguments& arguments) {
    m_Options = options;
    m_Arguments = arguments;
}

void cli::I_Command::setValidOptions(const Options& options) {
    m_Valid_Options = options;
}

void cli::I_Command::setValidArguments(const Arguments& args) {
    m_Valid_Arguments = args;
}

cli::I_Command::CommandPtr cli::I_Command::create(const ArgList& Function_arguments) {
    const auto arguments = Function_arguments.getArgumetns();
    const auto options = Function_arguments.getOptions();

    if (!areArgumentsValid(arguments)) {
        throw std::runtime_error("Invalid Argument\n");
    }

    if (!areOptionsValid(options)) {
        throw std::runtime_error("Invalid Options");
    }

    return std::make_shared<cli::I_Command>((arguments, options));
}

bool cli::I_Command::areOptionsValid(const Options& options) {
    for (const auto& elem : options) {
        if (!m_Valid_Options.contains(elem)) {
            return false;
        }
    }
    return true;
}

bool cli::I_Command::areArgumentsValid(const Arguments& arguments) {
    for (const auto& elem : arguments) {
        if (!m_Valid_Arguments.contains(elem)) {
            return false;
        }
    }
    return true;
}
