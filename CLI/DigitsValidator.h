#pragma once
#include "TokenValidator.h"

namespace cli {
    class DigitsValidator : public TokenValidator {
        public:
        DigitsValidator() = default;
        ~DigitsValidator() = default;
        public:
        bool validate(const Token) override;
        private:
        bool isDigit(const char) const;
        bool hasAlphaNumeric(const Token) const;
        bool doesContainDigit(const Token) const;
    };
    #include "DigitsValidator.inl"
}; //namespace cli