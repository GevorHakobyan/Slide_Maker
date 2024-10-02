#include "InvalidCharacter_Cerr.h"

cli::InvalidCharacter_Cerr::InvalidCharacter_Cerr(const Messeage& messeage, const Text& text, const Index index)
: Exception{messeage}, m_text{text}, m_Index{index} {} 

const char* cli::InvalidCharacter_Cerr::what() const {
    const auto baseMesseage = Exception::what();
    const auto additionalInfo = '\n' + "In token: " + m_text + " On Character: " + m_text[m_Index] + "\n";
    const auto fullMesseage = baseMesseage + additionalInfo;

    return fullMesseage.c_str();
}