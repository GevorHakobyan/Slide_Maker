#pragma once
#include "SlideMaker.h"
#include "Exiter.h"

namespace cli {
    class Initializer {
        public:
        static void InitializeCommands();
        private:
        static void setSlideMaker();
        static void setExiter();
    };
}; //namespace cli