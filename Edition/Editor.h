#pragma once
#include <memory>
#include <vector>
#include "Command.h"
#include "Storage.h"

namespace edition {
    class Editor {
        public: //usings
        using thisPtr = std::shared_ptr<Editor>;
        using CommandList = std::vector<std::string_view>;
        using Command = cli::I_Command;

        public: //methods
        static thisPtr getInstance();
        void Edit(const Command&);

        private:
        Editor() = default;
        ~Editor() = default;

        private: //data members
        static thisPtr m_ptr;
    };
}; //namespace edition