#include "FunctionArgument.h"

cli::Argument_list::Argument_list(const Options& option, const ArgList& argument) 
: m_options{option}, m_arguments{argument} {};

const cli::Argument_list::ArgList& cli::Argument_list::getArgumetns() const {
    return m_arguments;
} 

const cli::Argument_list::Options& cli::Argument_list::getOptions() const {
    return m_options;
}