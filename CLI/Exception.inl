#include "Exception.h"

cli::Exception::Exception(const Messeage& messeage, const Location& location) 
: m_messeage{messeage}, m_ErrorLocation{location} {};

const char* cli::Exception::what() const {
    const auto fileName = m_ErrorLocation.file_name();
    const auto lineNumber = m_ErrorLocation.line();
    const auto fullMesseage = (m_messeage + " In: " + fileName) + (" On Line: " + lineNumber + '\n');
    return fullMesseage.c_str();
}