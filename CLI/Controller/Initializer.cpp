#include "Initializer.h"

void cli::Initializer::InitializeValidCommands() {
    setSlideAdder();
    setExiter();
}

void cli::Initializer::InitializeValidItems() {
    //static map initialize 
}

void cli::Initializer::setSlideAdder() {
    cli::option opt = "t";
    cli::argument argsType = "String";
    cli::Slide_Maker::setValidInfo(opt, argsType);
}

void cli::Initializer::setExiter() {
    cli::option opt = cli::EMPTY::empty;
    cli::argument argsType = cli::EMPTY::empty;
    cli::Exiter::setValidInfo(opt, argsType);
}