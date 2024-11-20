#pragma once
#include "Types.h"
#include "InvalidCommand_Cerr.h"
#include <exception>

namespace cli {
    struct CommandInfo {
        using Info = std::pair<C_name, C_arguments>;
        C_name _name{};
        C_arguments _arguments{};
        Info getInfo() const;
    };
}; //namespace cli