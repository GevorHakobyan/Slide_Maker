#pragma once
#include "Exception.h"

namespace cli {
    class InvalidArgument_Cerr : public Exception {
        using InvalidArgument = std::string;
        public:
        InvalidArgument_Cerr(const Messeage&, const InvalidArgument&);
        const char* what() const noexcept override;
        private:
        InvalidArgument m_invalidArgument;
    };
    #include "InvalidArgument_Cerr.h"
}; //namespace cli