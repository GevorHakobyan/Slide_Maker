#pragma once
#include "Validator.h"
#include "IncompleteData_Cerr.h"

namespace cli {
    class TextBoxValidator : public Validator {
        void Validate(const Data&) const override;
        private:
        bool isTextGiven(const Data&) const;
        bool isLocationGiven(const Data&) const;
        bool isSizeGiven(const Data&) const;
    };    
};