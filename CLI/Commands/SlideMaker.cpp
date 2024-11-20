#include "SlideMaker.h"

cli::Slide_Maker::Slide_Maker(const Arguments& args)
: I_Command(args) {};

bool cli::Slide_Maker::Execute() {
    // auto StoreManagerPtr = edition::StoreManager::getInstance();
    // StoreManagerPtr->addSlide(m_SlideInfo);
    return true;
}

cli::I_Command::CommandPtr cli::Slide_Maker::create(const ArgList& Function_arguments) {
    const auto arguments = Function_arguments.getArgumetns();

    validateInfo(arguments);

    return std::move(std::make_unique<cli::Slide_Maker>(arguments));
}

