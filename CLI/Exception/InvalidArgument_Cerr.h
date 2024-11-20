#pragma once
#include "Exception.h"
#include "Types.h"

namespace cli {
    class InvalidArgument_Cerr : public Exception {
        using InvalidArgument = cli::argument;
        public:
        InvalidArgument_Cerr(const Messeage&,  const InvalidArgument&, const Location& = std::source_location::current());
        const char* what() const noexcept override;
        private:
        void setInvalidArgument(const InvalidArgument&);
        void setMesseage() override;
        private:
        Messeage m_invalidArgument;
    };
}; //namespace cli