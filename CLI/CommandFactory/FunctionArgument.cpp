#include "FunctionArgument.h"

cli::Argument_list::Argument_list(const ArgList& argument) 
: m_arguments{argument} {};

const cli::Argument_list::ArgList& cli::Argument_list::getArgumetns() const {
    return m_arguments;
} 

