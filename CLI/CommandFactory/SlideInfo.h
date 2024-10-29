#pragma once
#include <string>

namespace cli {
    class SlideInfo {
        public:
        using Title = std::string;
        using Text = std::string;

        public:
        SlideInfo() = default;
        ~SlideInfo() = default;
        void setTitile(const Title&);
        void setText(const Text&);
        const Title& getTitle() const;
        const Text& getText() const;

        private:
        Title m_slideTitle{};
        Text m_text{};
    };
};