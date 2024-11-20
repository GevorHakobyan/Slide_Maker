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
    const auto[name, arguments] = commandInf.getInfo();
    Value commandPtr = getFunction(name);
    
    Argument_list argList(arguments);
    return std::move(commandPtr->create(argList));
}

void cli::CommandCreator::setValidCommands() {
    auto val1 = std::make_shared<cli::Slide_Maker>(cli::Slide_Maker());
    m_validCommands["addslide"] = std::move(val1);
    
    auto val2 = std::make_shared<cli::Exiter>(cli::Exiter());
    m_validCommands["exit"] = std::move(val2);

    auto val3 = std::make_shared<cli::ShapeAdder>(cli::ShapeAdder());
    m_validCommands["addshape"] = std::move(val3);
} 

