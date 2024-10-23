#pragma once
#include "Exception.h"
#include <variant>

namespace document {

    class InvalidAttribute_Cerr : public cli::Exception {
        public:
        using Attribute = std::variant<int, std::string, float>;

        public:
        InvalidAttribute_Cerr(const Messeage&, Attribute,  const Location& = Location::current());
        void setMesseage() override;

        private:
        Attribute m_invalidAttribute;
    };
    
}; //namespace document