#include "Controller.h"

cli::Controller::Controller() 
: m_parser{std::make_unique<Parser>()} {};

void cli::Controller::start(std::istream& stream) {
    CInitializer::InitializeValidCommands();
    bool Continue{true};

        while(Continue) {
            
            try{
                auto command = fetch(stream);
                Continue = Exectute(command);

            } catch(const Exception& err) {
                std::cerr << err.what() << "\n";
                }
        } 
}

cli::Controller::CommandPtr cli::Controller::fetch(std::istream& stream) {
   return m_parser->getCommand(stream);
}

bool cli::Controller::Exectute(CommandPtr& command) {
    return command->Execute();
}

