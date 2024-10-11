#include "CommandCreator.h"

cli::CommandCreator::CommandCreator() {
    setValidCommands();
}

const cli::CommandCreator::Value cli::CommandCreator::getFunction(const Key& key) {
    if (m_validCommands.contains(key)) {
        return m_validCommands[key];
    }
    throw cli::InvalidCommand_Cerr("Invalid command name", key, std::source_location::current());
}

cli::CommandCreator::CommandPtr cli::CommandCreator::CreateCommand(const CommandInfo& commandInf) {
    const auto[name, options, arguments] = commandInf.getInfo();
    Value funcPtr;

    try{
        funcPtr = getFunction(name);
    } catch(cli::InvalidCommand_Cerr& err) {
        throw;
    }

    Argument_list argList(options, arguments);
    return std::move(funcPtr(argList));
}

void cli::CommandCreator::setValidCommands() {
    const auto val = cli::Slide_Maker::create;
    m_validCommands["makeslide"] = std::move(val);
}

