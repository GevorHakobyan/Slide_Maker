#pragma once
#include <string>

namespace model {

    struct S_Type {
        public: //usings
        using TypeName = std::string_view;

        public: //methods
        S_Type(std::string_view);
        void setType(std::string_view);
        const TypeName getType() const;
        
        //data member
        private:
        TypeName m_name;
    };

} //namespace model