#include "Controller.h"

cli::Controller::Controller() 
: m_parser{std::make_unique<Parser>()} {};

void cli::Controller::start(std::istream& stream) {
    Initializer::initialize();
    try{
        while(true) {
            auto command = fetch(stream);
            Exectute(command);
        }
    } catch(const Exception& err) {
        std::cerr << err.what() << "\n";
    }
}

cli::Controller::CommandPtr cli::Controller::fetch(std::istream& stream) {
   return m_parser->getCommand(stream);
}

void cli::Controller::Exectute(CommandPtr& command) {
    command->Execute();
}

