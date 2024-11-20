#include "Command.h"
cli::I_Command::Options_to_Args cli::I_Command::m_Valid_Info{};

cli::I_Command::I_Command(const Options& options, const Arguments& arguments) {
    m_Options = options;
    m_Arguments = arguments;
}


void cli::I_Command::validateInfo(const Options& options, const Arguments& arguments) {
    if (options.size() != arguments.size()) {
        //throw??
    }

    auto argIter = arguments.begin();

    for (const auto& opt : options) {

        auto optionIter = m_Valid_Info.find(opt);
        if (m_Valid_Info.end() ==  optionIter) {
            throw cli::InvalidOption_Cerr("Invalid Option", opt, std::source_location::current());
        }

        if (!hasAppropriateValue(optionIter, argIter)) {
            throw cli::InvalidArgument_Cerr("Invalid Argument", *argIter, std::source_location::current());
        }
        ++argIter;
    }
}

bool cli::I_Command::hasAppropriateValue(const Options_to_Args::iterator optionsIter, const Arguments::const_iterator argument) {
    auto userArgument = *argument;
    auto validArgument = optionsIter->second;
    return userArgument.index() == validArgument.index();
    //variant<int, bool, string>.index
}

void cli::I_Command::setValidInfo(const cli::option opt, const cli::argument arg) {
    //you can use this method to add any new option to argument pair*
    m_Valid_Info[opt] = arg;
}
