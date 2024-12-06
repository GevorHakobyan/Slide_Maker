#include "TextBoxValidator.h"

namespace cli {
    void TextBoxValidator::Validate(const Data& data) const {
        if (!isTextGiven(data)) {
            throw IncompleteData_Cerr("Empty text box", std::source_location::current());
        }

        if (!isLocationGiven(data)) {
            throw IncompleteData_Cerr("Location isn't provided", std::source_location::current());
        }

        if (!isSizeGiven(data)) {
            throw IncompleteData_Cerr("Size isn't privided", std::source_location::current());
        }
    }

    bool TextBoxValidator::isTextGiven(const Data& data) const {
        const auto txtIter = data.find("txt");
        if (txtIter == data.end()) {
            return false;
        }
        return true;
    }

    bool TextBoxValidator::isLocationGiven(const Data& data) const {
        const auto lcIter = data.find("lc");
        if (lcIter == data.end()) {
            return false;
        }
        return true;
    }

    bool TextBoxValidator::isSizeGiven(const Data& data) const {
        const auto wdIter = data.find("wd");
        const auto lnIter = data.find("ln");
        if (wdIter == data.end() || lnIter == data.end()) {
            return false;
        }
        return true;
    }    
}