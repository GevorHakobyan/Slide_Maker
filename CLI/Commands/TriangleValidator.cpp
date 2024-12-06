#include "TriangleValidator.h"

namespace cli {
    void TriangleValidator::Validate (const Data& data) const {
        if (!areVertexesGiven(data)) {
            throw IncompleteData_Cerr("Vertexes are missing", std::source_location::current());
        }
    }

    bool TriangleValidator::areVertexesGiven(const Data& data) const {
        const auto vtIter = data.find("vt");
        if (vtIter == data.end()) {
            return false;
        }
        return true;
    }
}; //namespace cli