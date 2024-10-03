#include "CommandCreator.h"
cli::CommandCreator::Function_map cli::CommandCreator::m_validCommands;

cli::CommandCreator::CommandCreator() {
    setValidCommands();
}

const cli::CommandCreator::Value cli::CommandCreator::getFunction(const Key& key) {
    if (m_validCommands.contains(key)) {
        return m_validCommands[key];
    }
    throw cli::InvalidCommand_Cerr("Invalid command name", key);
}

cli::CommandCreator::CommandPtr cli::CommandCreator::CreateCommand(const CommandInfo& command) {
    const auto[name, options, arguments] = command.getInfo();
    Value ptr;

    try{
        ptr = getFunction(name);
    } catch(cli::InvalidCommand_Cerr& err) {
        throw;
    }

    Argument_list argList(options, arguments);
    const auto Command = ptr(argList);
    return std::make_shared<I_Command>(Command);
}

void cli::CommandCreator::setValidCommands() {
    const auto val = cli::Slide_Maker::create;
    m_validCommands["make slide"] = std::move(val);
}

