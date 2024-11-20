#pragma once
#include "SlideMaker.h"
#include "Exiter.h"

namespace cli {
    class Initializer {
        public:
        static void InitializeValidCommands();
        static void InitializeValidItems();
        private:
        static void setSlideAdder();
        static void setExiter();
        static void setShapeAdder();
    };
}; //namespace cli