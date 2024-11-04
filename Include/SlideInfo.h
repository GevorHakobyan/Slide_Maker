#pragma once
#include <string>
#include <optional>

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
        const std::optional<Title&> getTitle() const;
        const std::optional<Text&> getText() const;

        private:
        Title m_slideTitle{};
        Text m_text{};
    };
};