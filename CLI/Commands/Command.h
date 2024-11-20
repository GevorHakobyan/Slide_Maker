#pragma once
#include "FunctionArgument.h"
#include "InvalidArgument_Cerr.h"
#include "InvalidOption_Cerr.h"
#include <unordered_map>
#include <memory>

namespace cli {
    class I_Command {
        public:
        using ArgList = cli::Argument_list;
        using Arguments =  cli::Argument_list::ArgList;
        using Options_to_Args = cli::C_arguments;
        using CommandPtr = std::unique_ptr<I_Command>;
        public:
        I_Command(const Arguments&);
        I_Command() = default;
        virtual ~I_Command() = default;

        public: //static methods
        virtual CommandPtr create(const ArgList& ) = 0;
        virtual bool Execute() = 0;
        static void addValue(const cli::option, const cli::argument);

        protected://helper ones
        void validateInfo(const Arguments&);

        protected:
        static Options_to_Args m_Valid_Info;

        protected:
        Arguments m_Arguments;
    };
} //namespace cli