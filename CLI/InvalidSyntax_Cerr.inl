#include "InvalidSyntax_Cerr.h"
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T1{"Provided argument before option\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T2{"Provided argument before name\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T3{"Provided option before argument\n"};
cli::InvalidSyntax_Cerr::Messeage cli::InvalidSyntax_Cerr::Error_Type::m_T4{"Provided option before name\n"};

cli::InvalidSyntax_Cerr::InvalidSyntax_Cerr(const Messeage& messeage, const Error cerr)
: Exception(messeage), m_cerr{cerr} {};

const char* cli::InvalidSyntax_Cerr::what() const {
    const auto baseMesseage = Exception::what();
    const auto additionalMesseage = '\n' + Error_Type::getMesseage(m_cerr);
    const auto fullMesseage = baseMesseage + additionalMesseage;

    return fullMesseage.c_str();
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
    }

    return Messeage{}; //will never reach here not to get compiler warning
}

