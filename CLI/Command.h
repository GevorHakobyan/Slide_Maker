#pragma once
#include "FunctionArgument.h"

namespace cli {
    class I_Command {
        public:
        using ArgList = cli::Argument_list;
        using Options = cli::Argument_list::Options;
        using Arguments =  cli::Argument_list::ArgList;
        public:
        I_Command(const Options&, const Arguments&);
        I_Command() = default;

        public: //static methods
        static I_Command create(const ArgList& );
        void print() const;
        private://static helper ones
        static bool areOptionsValid(const Options&);
        static bool areArgumentsValid(const Arguments&);
        static void setValidOptions(const Options&);
        static void setValidArguments(const Arguments&);

        private:
        static Options m_Valid_Options;
        static Arguments m_Valid_Arguments;

        private:
        Options m_Options;
        Arguments m_Arguments;
    };
    #include "Command.inl"
} //namespace cli