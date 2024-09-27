#pragma once

#include "Command.h"
#include "Parser.h"
#include "FunctionArgument.h"
#include <unordered_map>
#include <functional>

namespace cli {
    class CommandCreator{
        public: //usings
        using thisPtr = std::shared_ptr<CommandCreator>;
        using CommandInfo = cli::Parser::CommandInfo;
        using Key = cli::Parser::C_name;
        using Arguments = cli::Argument_list;
        using FunctionType = cli::I_Command(Arguments);
        using Value = std::function<FunctionType>;
        using Function_map = std::unordered_map<Key, Value>; 

        public: //methods
        CommandCreator(const CommandCreator&) = delete;
        CommandCreator& operator=(const CommandCreator&) = delete;
        static thisPtr getInstance();
        cli::I_Command CreateCommand(const CommandInfo&);
        void setValidCommands(const Function_map&);
        ~CommandCreator() = default;

        private: //helper methods
        const Value getFunction(const Key&);

        private: //data members
        CommandCreator() = default;
        static thisPtr m_ptr;
        static std::mutex m_mutex;
        Function_map m_validCommands{};
    };
    #include "CommandCreator.inl"
} //namespace cli