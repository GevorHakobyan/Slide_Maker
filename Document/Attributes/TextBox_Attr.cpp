#include "../../Include/TextBox_Attr.h"

document::TextBox_Attr::TextBox_Attr(Color color, Length length, Width width, LetterSize size, const Content& content)
: I_Attributes(color, length, width, 5) {
    setLetterSize(size);
    setContent(content);
}

void document::TextBox_Attr::setLetterSize(LetterSize letterSize) {
    m_letterSize = letterSize;
}

void document::TextBox_Attr::setContent(const Content& title) {
    m_content = title;
}

const document::TextBox_Attr::LetterSize document::TextBox_Attr::getSize() const {
    return m_letterSize;
}

const document::TextBox_Attr::Content document::TextBox_Attr::getContent() const {
    return m_content;
}