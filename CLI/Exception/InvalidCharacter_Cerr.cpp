#include "InvalidCharacter_Cerr.h"

cli::InvalidCharacter_Cerr::InvalidCharacter_Cerr(const Messeage& messeage, const Text& text, const Index index, const Location& loc)
: Exception{messeage, loc}, m_text{text}, m_Index{index} {
    setMesseage();
} 

const char* cli::InvalidCharacter_Cerr::what() const noexcept {
    
    return m_messeage.c_str();
}

void cli::InvalidCharacter_Cerr::setMesseage() {
    const auto baseMesseage = Exception::what();
    const auto additionalInfo = '\n' + "In token: " + m_text + " On Character: " + m_text[m_Index] + "\n";
    m_messeage = baseMesseage + additionalInfo;
}