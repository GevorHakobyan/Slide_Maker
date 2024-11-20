#include "Command.h"
cli::I_Command::Options_to_Args cli::I_Command::m_Valid_Info{};

cli::I_Command::I_Command(const Arguments& arguments) {
    m_Arguments = arguments;
}


void cli::I_Command::validateInfo(const Arguments& arguments) {
    for (const auto elem : arguments) {
        const auto iter = m_Valid_Info.find(elem.first);
        if (iter == m_Valid_Info.end()) {
            throw cli::InvalidOption_Cerr("Invalid Option", elem.first, std::source_location::current());
        }

        if (iter->second.index() != elem.second.index()) {
            throw cli::InvalidArgument_Cerr("Invalid Argument", elem.second, std::source_location());
        }
    } 
}

void cli::I_Command::addValue(const cli::option opt, const cli::argument arg) {
    //you can use this method to add any new option to argument pair*
    m_Valid_Info[opt] = arg;
}
