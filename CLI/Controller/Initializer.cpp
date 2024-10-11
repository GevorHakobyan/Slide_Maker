#include "Initializer.h"

void cli::Initializer::initialize() {
    cli::Slide_Maker::setValidArguments();
    cli::Slide_Maker::setValidOptions();
}