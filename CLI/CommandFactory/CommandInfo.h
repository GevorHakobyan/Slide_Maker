#pragma once
#include "Types.h"

namespace cli {
    struct CommandInfo {
        using Type = std::string;
        using Info = std::tuple<C_name, Type, C_options, C_arguments>;
        C_name _name{};
        C_options _options{};
        C_arguments _arguments{};
        Type _type{};
        Info getInfo() const;
    };
}; //namespace cli