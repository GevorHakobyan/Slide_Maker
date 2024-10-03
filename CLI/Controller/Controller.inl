#include "Controller.h"

void cli::Controller::start(std::istream& stream) {
    while(true) {
        auto command = fetch(stream);
        Exectute(command);
    }
}

cli::Controller::CommandPtr cli::Controller::fetch(std::istream& stream) {
    return std::make_shared<cli::I_Command>(m_parser->getCommand(stream));
}

void cli::Controller::Exectute(CommandPtr command) {
    command->Execute();
}

cli::Controller::thisPtr cli::Controller::getInstance() {
    static thisPtr m_ptr = std::make_shared<Controller>(Controller());
    return m_ptr;
}