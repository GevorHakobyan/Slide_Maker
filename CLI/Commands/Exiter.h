#pragma once
#include "Command.h"

namespace cli {
    class Exiter : public I_Command {
        public:
        Exiter() = default;
        Exiter(const Arguments&);
        bool Execute() override;
        CommandPtr create(const Arguments&) override;
        static void addValue(const cli::option, const cli::argument);
        private:
        static Arguments m_Valid_Info;
    };
}; //namespace cli