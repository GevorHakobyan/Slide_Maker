#pragma once
#include "Exception.h"

namespace cli{
    class InvalidCommand_Cerr : public Exception{
        private:
        using CommandName = std::string;
        public:
        InvalidCommand_Cerr(const Messeage&, const CommandName&);
        const char* what() const noexcept override;
        private:
        CommandName m_invalidCommand{};
    };
    #include "InvalidCommand_Cerr.inl"
}; //namespace cli