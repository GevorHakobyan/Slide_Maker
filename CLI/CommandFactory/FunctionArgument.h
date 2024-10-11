#pragma once
#include "Types.h"

namespace cli {
struct Argument_list{
        using ArgList = cli::C_arguments; 
        using Options = cli::C_options;
        public:
        Argument_list(const Options& op, const ArgList& arg);
        const ArgList& getArgumetns() const;
        const Options& getOptions() const;
        public:
        Options m_options;
        ArgList m_arguments;
    };
};//namespace cli