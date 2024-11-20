#pragma once
#include "IAttributes.h"
#include "SlideMaker.h"
#include "Exiter.h"
#include "ShapeAdder.h"

namespace cli {
    class Initializer {
        using Types = document::IAttributes;
        public:
        static void InitializeValidCommands();
        private:
        static void setSlideAdder();
        static void setShapeAdder();
        static void setExiter();
    };
}; //namespace cli