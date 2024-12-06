#pragma once
#include "InvalidArgument_Cerr.h"
#include "InvalidOption_Cerr.h"
#include <unordered_map>
#include <memory>

namespace cli {
    class I_Command {
        public:
        using Options_to_Args = cli::C_arguments;
        using Arguments = cli::C_arguments;
        using CommandPtr = std::unique_ptr<I_Command>;
        public:
        I_Command(const Arguments&);
        I_Command() = default;
        virtual ~I_Command() = default;

        public: //static methods
        virtual CommandPtr create(const Arguments& ) = 0;
        virtual bool Execute() = 0;

        protected://helper ones
        virtual void validateInfo(const Arguments&, const Arguments&) const;


        protected:
        Arguments m_Arguments;
    };
} //namespace cli