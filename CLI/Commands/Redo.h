#pragma once
#include "Command.h"
#include "StoreManager.h"

namespace cli {
    class Redo : public I_Command {
        public:
        Redo() = default;
        Redo(const Arguments&);
        CommandPtr create(const Arguments&) override;
        bool Execute() override;
        void static addValue(const cli::option&, cli::argument);

        private:
        static Arguments m_ValidInfo;
    };
}; //namespace cli