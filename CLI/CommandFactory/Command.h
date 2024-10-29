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
        using Options_to_Args = std::unordered_map<cli::option, cli::argument>;
        using Options = cli::Argument_list::Options;
        using CommandPtr = std::unique_ptr<I_Command>;
        public:
        I_Command(const Options&, const Arguments&);
        I_Command() = default;
        virtual ~I_Command() = default;

        public: //static methods
        virtual CommandPtr create(const ArgList& ) = 0;
        virtual bool Execute() = 0;
        static void setValidInfo(const cli::option, const cli::argument);

        protected://helper ones
        void validateInfo(const Options&, const Arguments&);
        bool hasAppropriateValue(const Options_to_Args::iterator, Arguments::const_iterator);

        protected:
        static Options_to_Args m_Valid_Info;

        protected:
        Options m_Options;
        Arguments m_Arguments;
    };
} //namespace cli