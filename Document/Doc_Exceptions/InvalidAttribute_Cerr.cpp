#include "../Include/InvalidAttribute_Cerr.h"

document::InvalidAttribute_Cerr::InvalidAttribute_Cerr(const Messeage& messeage, Attribute attr, const Location& locate)
: Exception(messeage, locate), m_invalidAttribute{attr} {
    setMesseage();
}

void document::InvalidAttribute_Cerr::setMesseage() {
    std::string fileName = m_ErrorLocation.file_name();
    int lineNumber = (m_ErrorLocation.line());

    m_messeage = m_messeage + "\n";
}
