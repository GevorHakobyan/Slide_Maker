#pragma once
#include "Exception.h"

namespace cli {
    class InvalidOption_Cerr : public Exception {
        private:
        using OptionName = std::string;
        public:
        InvalidOption_Cerr(const Messeage&, const OptionName&);
        const char* what() const noexcept override;
        private:
        OptionName m_invalidOption;
    };
}; //namespace cli