#pragma once
#include "Validator.h"
#include "IncompleteData_Cerr.h"

namespace cli {
    class CircleValidator : public Validator {
        public:
        void Validate (const Data&) const override;

        private:
        bool isRadiusGiven(const Data&) const;
        bool isCenterGiven(const Data&) const;
    };
}; //namespace cli