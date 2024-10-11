#pragma once
#include "FunctionArgument.h"
#include "InvalidArgument_Cerr.h"
#include "InvalidOption_Cerr.h"
#include <memory>

namespace cli {
    class I_Command {
        public:
        using ArgList = cli::Argument_list;
        using Options = cli::Argument_list::Options;
        using Arguments =  cli::Argument_list::ArgList;
        using CommandPtr = std::unique_ptr<I_Command>;
        public:
        I_Command(const Options&, const Arguments&);
        I_Command() = default;
        virtual ~I_Command() = default;

        public: //static methods
        static CommandPtr create(const ArgList& );
        virtual void Execute();
        private://static helper ones
        static void validateOptions(const Options&);
        static void validateArguments(const Arguments&);
        static void setValidOptions(const Options&);
        static void setValidArguments(const Arguments&);

        protected:
        static Options m_Valid_Options;
        static Arguments m_Valid_Arguments;

        protected:
        Options m_Options;
        Arguments m_Arguments;
    };
} //namespace cli