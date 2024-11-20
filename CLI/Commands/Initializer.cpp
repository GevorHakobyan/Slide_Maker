#include "Initializer.h"

void cli::Initializer::InitializeValidCommands() {
    setSlideAdder();
    setShapeAdder();
    setExiter();
}

void cli::Initializer::setSlideAdder() {
    cli::argument argsType = cli::String{};

    cli::option opt = "t";
    cli::Slide_Maker::addValue(opt, argsType);

    opt = "ct";
    cli::Slide_Maker::addValue(opt, argsType);
}

void cli::Initializer::setExiter() {
    cli::option opt = "";
    cli::argument argsType = cli::EMPTY::empty;
    cli::Exiter::addValue(opt, argsType);
}

void cli::Initializer::setShapeAdder() {
    cli::option opt1 = "lc"; //location
    cli::argument argType1 = cli::Pair{};
    cli::ShapeAdder::addValue(opt1, argType1);

    cli::option opt2 = "cn"; //center
    cli::argument argType2 = cli::Pair{};
    cli::ShapeAdder::addValue(opt2, argType2);

    cli::option opt3 = "vt"; //vertexes
    cli::argument argType3 = cli::Tuple{};
    cli::ShapeAdder::addValue(opt3, argType3);

    cli::option opt4 = "r"; //radius
    cli::argument argType4 = float{};
    cli::ShapeAdder::addValue(opt4, argType4);

    cli::option opt5 = "ln"; //length
    cli::argument argType5 = float{};
    cli::ShapeAdder::addValue(opt5, argType5);

    cli::option opt6 = "wd"; //width
    cli::argument argType6 = float{};
    cli::ShapeAdder::addValue(opt6, argType6);
}

