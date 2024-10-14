#include "InvalidAttribute_Cerr.h"

document::InvalidAttribute_Cerr::InvalidAttribute_Cerr(const Messeage& messeage, const Location& locate, Attribute attr)
: Exception(messeage, locate), m_invalidAttribute{attr} {
    setMesseage();
}

void document::InvalidAttribute_Cerr::setMesseage() {
    std::string fileName = m_ErrorLocation.file_name();
    int lineNumber = (m_ErrorLocation.line());

    m_messeage = m_messeage + "\n";
}
