#pragma once
#include "Exception.h"

namespace document {
    class Invalid_Index : public cli::Exception {
        public:
        using Index = size_t;

        public:
        Invalid_Index(const Messeage&, Index, Location = Location::current());
        ~Invalid_Index() = default;
        void setMesseage() override;
        
        private:
        Index m_invalidIndex;
    };
} //document

