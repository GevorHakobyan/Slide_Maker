#include "SlideMaker.h"

cli::Slide_Maker::Slide_Maker(const Options& opt, const Arguments& args)
: I_Command(opt, args) {};

void cli::Slide_Maker::Execute() {
    return;
}

void cli::Slide_Maker::setValidOptions() {
    std::variant<int, std::string, bool> opt = "a";
    m_Valid_Options.insert(std::move(opt));
}

void cli::Slide_Maker::setValidArguments() {
    std::variant<int, std::string, bool> arg = 5;
    m_Valid_Arguments.insert(arg);
}