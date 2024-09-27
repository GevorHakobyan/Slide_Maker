#include <iostream>
#include "Parser.h"
#include "CommandCreator.h"
#include <sstream>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::istringstream obj(str);

    const auto ptr = cli::Parser::getInstance();
    const auto command = ptr->operator()(obj);
    
    const auto creatorPtr = cli::CommandCreator::getInstance();
    cli::CommandCreator::Function_map map;
    cli::CommandCreator::Value val = cli::I_Command::create;
    map["make slide "] = val;
    
    creatorPtr->setValidCommands(map);
    const auto Command = creatorPtr->CreateCommand(command);
    Command.print();
    return 0;
}