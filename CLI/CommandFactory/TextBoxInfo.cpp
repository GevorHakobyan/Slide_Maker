#include "TextBoxInfo.h"

void cli::TextBoxInfo::setContent(const Content& content) {
    _content = content;
}

const cli::TextBoxInfo::Content& cli::TextBoxInfo::getContent() const {
    return _content;
}

void cli::TextBoxInfo::setOwnerId(Owner id) {
    m_OwnerID = id;
}

cli::TextBoxInfo::Owner cli::TextBoxInfo::getOwnerId() const {
    return m_OwnerID;
}
