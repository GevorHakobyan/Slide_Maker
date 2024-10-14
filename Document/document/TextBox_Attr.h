#pragma once
#include "I_Attributes.h"
#include <string>

namespace document {
    struct TextBox_Attr : public I_Attributes {
        public:
        using LetterSize = float;
        using Title = std::string;

        public:
        TextBox_Attr(Color, Length, Width, LetterSize, const Title&);
        ~TextBox_Attr() = default;
        void setLetterSize(LetterSize);
        void setTitle(const Title&);
        const LetterSize getSize() const;
        const Title getTitle() const;

        private:
        LetterSize m_letterSize{};
        Title m_title{};
    };
}; //namespace document