#include "CmdInitializer.h"

void cli::CInitializer::InitializeValidCommands() {
    setSlideAdder();
    setShapeAdder();
    setExiter();
}

void cli::CInitializer::setSlideAdder() {
    cli::argument argsType = String{};

    cli::option opt = "tit"; //title
    cli::Slide_Maker::addValue(opt, argsType);

    opt = "ct"; //content
    cli::Slide_Maker::addValue(opt, argsType);

    opt = "ps"; //position
    argsType = size_t{};
    cli::Slide_Maker::addValue(opt, argsType);

    opt = "";
    argsType = cli::EMPTY::empty;
    cli::Slide_Maker::addValue(opt, argsType);
}

void cli::CInitializer::setExiter() {
    cli::option opt = "";
    cli::argument argsType = cli::EMPTY::empty;
    cli::Exiter::addValue(opt, argsType);
}

void cli::CInitializer::setShapeAdder() {
    cli::option opt1 = "lc"; //location
    cli::argument argType1 = cli::Pair{};
    cli::ShapeAdder::addValue(opt1, argType1);

    cli::option opt2 = "cn"; //center
    cli::argument argType2 = cli::Pair{};
    cli::ShapeAdder::addValue(opt2, argType2);

    cli::option opt3 = "vt"; //vertexes
    cli::argument argType3 = cli::Tuple{};
    cli::ShapeAdder::addValue(opt3, argType3);

    cli::option opt4 = "rd"; //radius
    cli::argument argType4 = float{};
    cli::ShapeAdder::addValue(opt4, argType4);

    cli::option opt5 = "ln"; //length
    cli::argument argType5 = float{};
    cli::ShapeAdder::addValue(opt5, argType5);

    cli::option opt6 = "wd"; //width
    cli::argument argType6 = float{};
    cli::ShapeAdder::addValue(opt6, argType6);

    cli::option opt7 = "cl"; //color
    cli::argument argType7 = Color{};
    cli::ShapeAdder::addValue(opt7, argType7);

    cli::option opt8 = "t"; //type
    cli::argument argType8 = String{};
    cli::ShapeAdder::addValue(opt8, argType8);

    cli::option opt9 = "oid";
    cli::argument argType9 = float{};
    cli::ShapeAdder::addValue(opt9, argType9);

    cli::option opt10 = "txt";
    cli::argument argType10 = String{};
    cli::ShapeAdder::addValue(opt10, argType10); 

    cli::ShapeAdder::setValidators();
}

