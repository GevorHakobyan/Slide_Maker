#include "CommandInfo.h"

cli::CommandInfo::Info cli::CommandInfo::getInfo() const {
    return {m_name, m_options, m_arguments};
}