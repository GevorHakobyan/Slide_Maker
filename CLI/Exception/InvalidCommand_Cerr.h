#pragma once
#include "Exception.h"

namespace cli{
    class InvalidCommand_Cerr : public Exception{
        private:
        using CommandName = std::string;
        public:
        InvalidCommand_Cerr(const Messeage&, const CommandName&, const Location& = std::source_location::current());
        const char* what() const noexcept override;
        private:
        void setMesseage() override;
        private:
        CommandName m_invalidCommand{};
    };
}; //namespace cli