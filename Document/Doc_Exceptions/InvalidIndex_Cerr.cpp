#include "InvalidIndex_Cerr.h"

document::Invalid_Index::Invalid_Index(const Messeage& messeage, Index invIndex, Location location)
: Exception{messeage, location} 
{
     m_invalidIndex = invIndex;   
}

void document::Invalid_Index::setMesseage() {
    std::string fileName = m_ErrorLocation.file_name();
    int lineNumber = (m_ErrorLocation.line());

    m_messeage = m_messeage + "\n" + "Index: " + std::to_string(m_invalidIndex) + " is Invalid\n";
}
