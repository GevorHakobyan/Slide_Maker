#include "InvalidSyntax_Cerr.h"
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T1{"Provided option before name\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T2{"Provided argument before name\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T3{"Provided argument before option\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T4{"Provided name after option\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T5{"Provided name after argument\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T6{"Provided option after argument\n"};

cli::InvalidSyntax_Cerr::InvalidSyntax_Cerr(const Messeage& messeage, const Error cerr, const Location& loc)
: Exception(messeage, loc), m_cerr{cerr} {
    setMesseage();
};

const char* cli::InvalidSyntax_Cerr::what() const noexcept {
    
    return m_messeage.c_str();
}

void cli::InvalidSyntax_Cerr::setMesseage() {
    auto baseMesseage = Exception::what();
    const auto additionalMesseage = '\n' + Error_Type::getMesseage(m_cerr);
    m_messeage = baseMesseage + additionalMesseage;
}

cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::getMesseage(const Error cerr) {
    switch(cerr) {
        case Error::T1 : {
            return m_T1;
            break;
        }

        case Error::T2 : {
            return m_T2;
            break;
        }

        case Error::T3 : {
            return m_T3;
            break;
        }

        case Error::T4 : {
            return m_T4;
            break;
        }

        case Error::T5 : {
            return m_T5;
            break;
        }

        case Error::T6 : {
            return m_T6;
            break;
        }
    }

    return Messeage{}; //will never reach here not to get compiler warning
}

