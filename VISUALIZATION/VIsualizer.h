#pragma once

#include "Command.h"
#include "Storage.h"
#include "memory"

namespace visual {
    class Visualizer {
        public://usings
        using Command = cli::I_Command;
        using ModelPtr = std::shared_ptr<document::Storage>;
        using thisPtr = std::shared_ptr<Visualizer>;

        public://methods
        void VisualizeCommand(const Command&);
        static thisPtr getInstance();

        private:
        static thisPtr m_ptr;
        ModelPtr m_model{nullptr};
    };
}//namespace visual