#pragma once
#include <memory>

namespace cli {
    class TokenValidator {
        public:
        using nextValidator = std::unique_ptr<TokenValidator>;
        using Token = char*;
        public:
        TokenValidator() = default;
        virtual ~TokenValidator() = default;
        void setNextValidator(const nextValidator);
        const nextValidator& getNextValidator() const;
        virtual bool validate(const Token) = 0;
        protected:
        nextValidator m_nextValidator{nullptr};
    };
    #include "TokenValidator.inl"
};//namespace cli