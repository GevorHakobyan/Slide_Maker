#include "SlidePrintValidator.h"

namespace cli {
    void SlidePrintValidator::Validate(const Data& data) const {
        const auto id = data.find("slide");
        if (id == data.end()) {
            throw InvalidCommand_Cerr("Invalid Command", "Print Slide", std::source_location::current());
        }

        if (data.size() > 1) {
            throw InvalidCommand_Cerr("Invalid Command", "Print Slide", std::source_location::current());
        }
    }
}; //namespace cli