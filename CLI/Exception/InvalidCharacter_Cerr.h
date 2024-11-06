#pragma once
#include "Exception.h"

namespace cli{
    class InvalidCharacter_Cerr : public Exception {
        private:
        using Index = size_t;
        using Text = std::string;
        public:
        InvalidCharacter_Cerr(const Messeage&, const Text&, const Index, const Location& = std::source_location::current());
        const char* what() const noexcept override;
        void setMesseage() override;
        private:
        Index m_Index;
        Text m_text{};
    };
}; //namespace cli