#include "CommandCreator.h"

cli::CommandCreator::thisPtr cli::CommandCreator::m_ptr{nullptr};
std::mutex cli::CommandCreator::m_mutex;

cli::CommandCreator::thisPtr cli::CommandCreator::getInstance() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_ptr) {
        m_ptr.reset(new CommandCreator());
    }
    return m_ptr;
}

const cli::CommandCreator::Value cli::CommandCreator::getFunction(const Key& key) {
    if (m_validCommands.contains(key)) {
        return m_validCommands[key];
    }
    throw std::runtime_error("Invalid Command Name\n");
}

cli::I_Command cli::CommandCreator::CreateCommand(const CommandInfo& command) {
    const auto[name, options, arguments] = command.getInfo();
    Value ptr;

    try{

        ptr = getFunction(name);

    } catch(std::runtime_error& err) {
        std::cout << err.what();
        return I_Command{};
    }

    Argument_list argList(options, arguments);
    const auto Command = ptr(argList);
    return Command;
}

void cli::CommandCreator::setValidCommands(const Function_map& map) {
    m_validCommands = map;
}

