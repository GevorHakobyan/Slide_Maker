#include "Initializer.h"

void cli::Initializer::InitializeCommands() {
    setSlideMaker();
    setExiter();
}

void cli::Initializer::setSlideMaker() {
    cli::option opt = "t";
    cli::argument argsType = "String";
    cli::Slide_Maker::setValidInfo(opt, argsType);
}

void cli::Initializer::setExiter() {
    cli::option opt = cli::EMPTY::empty;
    cli::argument argsType = cli::EMPTY::empty;
    cli::Exiter::setValidInfo(opt, argsType);
}