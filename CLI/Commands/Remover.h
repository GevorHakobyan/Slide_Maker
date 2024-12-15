#pragma once
#include "Command.h"
#include "StoreManager.h"
#include "InvalidCommand_Cerr.h"

namespace cli {
    class Remover : public I_Command {
        public:
        Remover() = default;
        Remover(const Arguments&);
        CommandPtr create(const Arguments&) override;
        bool Execute() override;
        static void addValue(const cli::option&, cli::argument);
        private:
        void validateInfo(const Arguments&);
        void isInfoAcceptable(const Arguments&);
        void isInfoComplete(const Arguments&);
        private:
        static Arguments m_ValidInfo;
    };
}; //namespace cli