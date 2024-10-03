#pragma once

#include "Command.h"
#include "Parser.h"
#include "FunctionArgument.h"
#include "InvalidArgument_Cerr.h"
#include "InvalidOption_Cerr.h"
#include "InvalidCommand_Cerr.h"
#include "SlideMaker.h"
#include <unordered_map>
#include <functional>

namespace cli {
    class CommandCreator{
        public: //usings
        using CommandInfo = cli::Parser::CommandInfo;
        using Key = cli::Parser::C_name;
        using Arguments = cli::Argument_list;
        using FunctionType = std::shared_ptr<cli::I_Command>(Arguments);
        using Value = std::function<FunctionType>;
        using Function_map = std::unordered_map<Key, Value>; 
        using CommandPtr = std::shared_ptr<cli::I_Command>;

        public: //methods
        static CommandPtr CreateCommand(const CommandInfo&);
        CommandCreator(); 
        ~CommandCreator() = default;

        private: //helper methods
        void setValidCommands();
        static const Value getFunction(const Key&);

        private: //data members
        static Function_map m_validCommands;
    };
    #include "CommandCreator.inl"
} //namespace cli