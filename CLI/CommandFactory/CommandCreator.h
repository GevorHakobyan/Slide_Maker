#pragma once

#include "InvalidArgument_Cerr.h"
#include "InvalidOption_Cerr.h"
#include "InvalidCommand_Cerr.h"
#include "CommandInfo.h"
#include "SlideMaker.h"
#include <unordered_map>
#include <functional>

namespace cli {
    class CommandCreator{
        public: //usings
        using Key = cli::C_name;
        using Arguments = cli::Argument_list;
        using FunctionType = std::unique_ptr<cli::I_Command>(Arguments);
        using Value = std::function<FunctionType>;
        using Function_map = std::unordered_map<Key, Value>; 
        using CommandPtr = std::unique_ptr<cli::I_Command>;

        public: //methods
        CommandPtr CreateCommand(const CommandInfo&);
        CommandCreator(); 
        ~CommandCreator() = default;

        private: //helper methods
        void setValidCommands();
        const Value getFunction(const Key&);

        private: //data members
        Function_map m_validCommands;
    };
} //namespace cli