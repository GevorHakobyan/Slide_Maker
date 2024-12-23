#include "RectValidator.h"

namespace cli {
    void RectValidator::Validate(const Data& data) const {
        if (!isSizeGiven(data)) {
            throw IncompleteData_Cerr("Size is missing", std::source_location::current());
            return;
        }

        if (!isLocationGiven(data)) {
            throw IncompleteData_Cerr("Location is missing", std::source_location::current());
        }
    }

    bool RectValidator::isSizeGiven(const Data& data) const {
        const auto wdIter = data.find("wd");
        const auto lnIter = data.find("ln");

        if (wdIter == data.end() || lnIter == data.end()) {
            return false;
        }

        return true;
    }

    bool RectValidator::isLocationGiven(const Data& data) const {
        const auto lcIter = data.find("lc");
        if (lcIter == data.end()) {
            return false;
        }
        return true;
    }
};