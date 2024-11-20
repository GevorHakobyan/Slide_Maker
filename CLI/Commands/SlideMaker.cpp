#include "SlideMaker.h"

cli::Slide_Maker::Slide_Maker(const Arguments& args)
: I_Command(args) {};

bool cli::Slide_Maker::Execute() {
    auto StoreManagerPtr = edition::StoreManager::getInstance();
    StoreManagerPtr->addSlide(std::move(m_Arguments));
    return true;
}

cli::I_Command::CommandPtr cli::Slide_Maker::create(const Arguments& collectedArgs) {
    validateInfo(collectedArgs);
    return std::move(std::make_unique<cli::Slide_Maker>(collectedArgs));
}

