#include "HelpPrintValidator.h"

namespace cli {
    void HelpPrintValidator::Validate(const Data& data) const {
        if (data.size() > 1) {
            throw InvalidCommand_Cerr("Invalid Command", "Help", std::source_location::current());
        }
    }
}