#include "ShapeAdder.h"


cli::ShapeAdder::ShapeAdder(const Arguments& arguments) 
: I_Command{arguments} {};

bool cli::ShapeAdder::Execute() {
    return true;
}

cli::I_Command::CommandPtr cli::ShapeAdder::create(const ArgList& Function_arguments) {
    const auto arguments = Function_arguments.getArgumetns();

    validateInfo(arguments);

    return std::move(std::make_unique<cli::ShapeAdder>(arguments));
}
