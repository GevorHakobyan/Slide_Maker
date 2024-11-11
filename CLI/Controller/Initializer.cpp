#include "Initializer.h"

void cli::Initializer::InitializeValidCommands() {
    setSlideAdder();
    setExiter();
    setBoxAdder();
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

void cli::Initializer::setBoxAdder() {
    cli::option opt = "c";
    cli::argument argsType = "String";
    cli::TextBoxAdder::setValidInfo(opt, argsType);

    cli::option opt2 = "i";
    cli::argument argsType2 = 5;
    cli::TextBoxAdder::setValidInfo(opt2, argsType2);
}