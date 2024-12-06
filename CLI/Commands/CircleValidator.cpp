#include "CircleValidator.h"

namespace cli {
    void CircleValidator::Validate(const Data& data) const {
        if (!isRadiusGiven(data)) {
            throw cli::IncompleteData_Cerr("Radius is missing", std::source_location::current());
            return;
        }

        if (!isCenterGiven(data)) {
            throw cli::IncompleteData_Cerr("Center Cooridnates are missing", std::source_location::current());
        }

    }

    bool CircleValidator::isCenterGiven(const Data& data) const {
        const auto cnIter = data.find("cn");
        if (cnIter == data.end()) {
            return false;
        }
        return true;
    }

    bool CircleValidator::isRadiusGiven(const Data& data) const {
        const auto rdIter = data.find("rd");
        if (rdIter == data.end()) {
            return false;
        }
        return true;
    }
}; //namespace cli