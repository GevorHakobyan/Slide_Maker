#pragma once
#include "Types.h"

namespace cli {
struct Argument_list{
        using ArgList = cli::C_arguments; 
        public:
        Argument_list(const ArgList& arg);
        const ArgList& getArgumetns() const;
        public:
        ArgList m_arguments;
    };
};//namespace cli