#include "SlideInfo.h"

void cli::SlideInfo::setTitile(const Title& title) {
    if (m_slideTitle.has_value()) {
        m_slideTitle.value().clear();
    }
    m_slideTitle = title;
}

void cli::SlideInfo::setText(const Text& text) {
    if (m_text.has_value()) {
        m_text.value().clear();
    }
    m_text = text;
}

const cli::SlideInfo::Title cli::SlideInfo::getTitle() const {
    return m_slideTitle;
}

const cli::SlideInfo::Text cli::SlideInfo::getText() const {
    return m_text;
}