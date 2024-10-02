#pragma once
#include "Exception.h"

namespace cli{
    class InvalidCharacter_Cerr : public Exception {
        private:
        using Index = size_t;
        using Text = std::string;
        public:
        InvalidCharacter_Cerr(const Messeage&, const Text&, const Index);
        const char* what() const noexcept override;
        private:
        Index m_Index;
        Text m_text{};
    };
    #include "InvalidCharacter_Cerr.h"
}; //namespace cli