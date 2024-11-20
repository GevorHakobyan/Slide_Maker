#include "ShapeAdder.h"


cli::ShapeAdder::ShapeAdder(const Arguments& arguments) 
: I_Command{arguments} {};

bool cli::ShapeAdder::Execute() {
    auto StoreManagerPtr = edition::StoreManager::getInstance();
    StoreManagerPtr->addItem(std::move(m_Arguments));
    return true;
}

cli::I_Command::CommandPtr cli::ShapeAdder::create(const Arguments& collectedArguments) {
    validateInfo(collectedArguments);
    return std::move(std::make_unique<cli::ShapeAdder>(collectedArguments));
}
