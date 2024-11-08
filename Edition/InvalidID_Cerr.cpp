#include "InvalidID_Cerr.h"

edition::InvalidID::InvalidID(const Messeage& meeseage, ID  id, Location location)
: Exception(meeseage, location) {
    m_invalidId = id;
};


void edition::InvalidID::setMesseage() {
    std::string fileName = m_ErrorLocation.file_name();
    int lineNumber = (m_ErrorLocation.line());

    m_messeage = m_messeage + "\n On ID: " + std::to_string(m_invalidId);
}