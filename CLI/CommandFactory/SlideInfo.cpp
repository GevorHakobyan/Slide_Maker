#include "../Include/SlideInfo.h"

void cli::SlideInfo::setTitile(const Title& title) {
    m_slideTitle.clear();
    m_slideTitle = title;
}

void cli::SlideInfo::setText(const Text& text) {
    m_text.clear();
    m_text = text;
}

const cli::SlideInfo::Title& cli::SlideInfo::getTitle() const {
    return m_slideTitle;
}

const cli::SlideInfo::Text& cli::SlideInfo::getText() const {
    return m_text;
}