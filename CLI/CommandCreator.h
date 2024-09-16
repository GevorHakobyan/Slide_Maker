#pragma once

#include "Command.h"
#include "Parser.h"

namespace cli {
    class CommandCreator{
        public: //usings
        using CommandCreatorPtr = std::shared_ptr<CommandCreator>;
        using Command = cli::I_Command;

        public: //methods
        static CommandCreatorPtr getInstance();
        Command getCommand();

        private:
        CommandCreator() = default;
        ~CommandCreator() = default;
        static CommandCreatorPtr m_ptr;
    };
} //namespace cli