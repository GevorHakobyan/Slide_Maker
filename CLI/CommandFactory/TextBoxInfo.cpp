#include "../../Include/TextBoxInfo.h"

void cli::TextBoxInfo::setContent(const Content& content) {
    _content = content;
}

const cli::TextBoxInfo::Content& cli::TextBoxInfo::getContent() const {
    return _content;
}