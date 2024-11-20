#include "CommandInfo.h"

cli::CommandInfo::Info cli::CommandInfo::getInfo() const {
    return {_name, _type, _options, _arguments};
}