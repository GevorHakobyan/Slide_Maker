#pragma once
#include "Validator.h"
#include "IncompleteData_Cerr.h"

namespace cli {
    class TriangleValidator : public Validator {
        void Validate (const Data&) const override;
        private:
        bool areVertexesGiven(const Data&) const;
    };
}; //namespace cli