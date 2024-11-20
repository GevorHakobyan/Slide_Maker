#pragma once
#include "Exception.h"
#include "Types.h"

namespace cli {
    class InvalidOption_Cerr : public Exception {
        private:
        using InvalidOption = cli::option;
        public:
        InvalidOption_Cerr(const Messeage&, const InvalidOption&, const Location& = std::source_location::current());
        const char* what() const noexcept override;
        void setMesseage() override;
        void setInvalidOption(const InvalidOption&);
        private:
        Messeage m_invalidOption;
    };
}; //namespace cli