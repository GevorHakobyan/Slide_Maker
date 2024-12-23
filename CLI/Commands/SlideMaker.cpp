#include "SlideMaker.h"

cli::I_Command::Arguments cli::Slide_Maker::m_Valid_Info{};

cli::Slide_Maker::Slide_Maker(const Arguments& args)
: I_Command(args) {};

bool cli::Slide_Maker::Execute() {
    auto StoreManagerPtr = edition::StoreManager::getInstance();
    m_Arguments["isMutuable"] = true;
    StoreManagerPtr->push(std::move(m_Arguments), "AddSlide");
    return true;
}

cli::I_Command::CommandPtr cli::Slide_Maker::create(const Arguments& collectedArgs) {
    validateInfo(collectedArgs, m_Valid_Info);
    return std::move(std::make_unique<cli::Slide_Maker>(collectedArgs));
}

void cli::Slide_Maker::addValue(const cli::option opt, const cli::argument arg) {
    m_Valid_Info[opt] = arg;
}