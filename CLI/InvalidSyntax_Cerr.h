#pragma once
#include "Exception.h"

namespace cli{

class InvalidSyntax_Cerr : public Exception {
    public:
    enum class Error{T1 = 1, T2, T3, T4};
    using Messeage = std::string;
    
    public:
    struct Error_Type{
        public:
        static Messeage getMesseage(const Error);
        private:
        static Messeage m_T1;
        static Messeage m_T2;
        static Messeage m_T3;
        static Messeage m_T4;
    };

    public:
    InvalidSyntax_Cerr(const Messeage&, const Error);
    const char* what() const noexcept override;
    private:
    Error m_cerr{};
};

}; //namespace cli