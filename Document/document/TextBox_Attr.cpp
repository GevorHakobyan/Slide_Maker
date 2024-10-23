#include "TextBox_Attr.h"

document::TextBox_Attr::TextBox_Attr(Color color, Length length, Width width, LetterSize size, const Title& title)
: I_Attributes(color, length, width) {
    setLetterSize(size);
    setTitle(title);
}

void document::TextBox_Attr::setLetterSize(LetterSize letterSize) {
    m_letterSize = letterSize;
}

void document::TextBox_Attr::setTitle(const Title& title) {
    m_title = title;
}

const document::TextBox_Attr::LetterSize document::TextBox_Attr::getSize() const {
    return m_letterSize;
}

const document::TextBox_Attr::Title document::TextBox_Attr::getTitle() const {
    return m_title;
}