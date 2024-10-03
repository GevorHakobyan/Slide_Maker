#pragma once
#include "FunctionArgument.h"

namespace cli {
    class I_Command {
        public:
        using ArgList = cli::Argument_list;
        using Options = cli::Argument_list::Options;
        using Arguments =  cli::Argument_list::ArgList;
        using CommandPtr = std::shared_ptr<I_Command>;
        public:
        I_Command(const Options&, const Arguments&);
        I_Command() = default;
        virtual ~I_Command() = default;

        public: //static methods
        static CommandPtr create(const ArgList& );
        virtual void Execute() = 0;
        private://static helper ones
        static bool areOptionsValid(const Options&);
        static bool areArgumentsValid(const Arguments&);
        static void setValidOptions(const Options&);
        static void setValidArguments(const Arguments&);

        protected:
        static Options m_Valid_Options;
        static Arguments m_Valid_Arguments;

        protected:
        Options m_Options;
        Arguments m_Arguments;
    };
    #include "Command.inl"
} //namespace cli