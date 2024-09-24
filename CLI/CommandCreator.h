#pragma once

#include "Command.h"
#include "Parser.h"

namespace cli {
    class CommandCreator{
        public: //usings
        using CommandCreatorPtr = std::shared_ptr<CommandCreator>;
        using Command = cli::I_Command;
        using name = cli::I_Command::name;
        using options = cli::I_Command::options;
        using arguments = cli::I_Command::arguments;

        public: //methods
        static CommandCreatorPtr getInstance();
        Command CreateCommand(name, options = {}, arguments = {});

        private: //data members
        CommandCreator() = default;
        ~CommandCreator() = default;
        static CommandCreatorPtr m_ptr;
    };
} //namespace cli