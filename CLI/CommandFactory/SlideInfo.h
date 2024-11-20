#pragma once
#include <string>
#include <optional>

namespace cli {
    class SlideInfo {
        public:
        using Title = std::optional<std::string>;
        using Text = std::optional<std::string>;

        public:
        SlideInfo() = default;
        ~SlideInfo() = default;
        void setTitile(const Title&);
        void setText(const Text&);
        const Title getTitle() const;
        const Text getText() const;

        private:
        Title m_slideTitle{};
        Text m_text{};
    };
};