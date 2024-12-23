#pragma once
#include "Validator.h"
#include "IncompleteData_Cerr.h"

namespace cli {
    class RectValidator : public Validator {
        public:
        void Validate(const Data&) const override;
        private:
        bool isSizeGiven(const Data&) const;
        bool isLocationGiven(const Data&) const;
    };
}; //namespace cli