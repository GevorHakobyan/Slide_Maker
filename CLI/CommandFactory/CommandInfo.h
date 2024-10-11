#pragma once
#include "Types.h"

namespace cli {
    struct CommandInfo {
        using Info = std::tuple<C_name, C_options, C_arguments>;
        C_name m_name{};
        C_options m_options{};
        C_arguments m_arguments{};
        Info getInfo() const;
    };
}; //namespace cli