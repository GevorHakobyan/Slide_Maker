#pragma once
#include "Command.h"
#include "StoreManager.h"

namespace cli {
    class Undo : public I_Command {
        public:
        Undo() = default;
        Undo(const Arguments&);
        CommandPtr create(const Arguments&) override;
        bool Execute() override;
        void static addValue(const cli::option&, cli::argument);

        private:
        static Arguments m_ValidInfo;
    };
}; //namespace cli