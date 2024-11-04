#pragma once
#include "I_Attributes.h"
#include <string>

namespace document {
    struct TextBox_Attr : public I_Attributes {
        public:
        using LetterSize = float;
        using Content = std::string;

        public:
        TextBox_Attr(Color, Length, Width, LetterSize, const Content&);
        ~TextBox_Attr() = default;
        void setLetterSize(LetterSize);
        void setContent(const Content&);
        const LetterSize getSize() const;
        const Content getContent() const;

        private:
        LetterSize m_letterSize{};
        Content m_content{};
    };
}; //namespace document