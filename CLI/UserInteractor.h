#pragma once
#include "CommandCreator.h"

namespace cli {
    class UserInteractor {
        public:
        void startProgram(); //will create a default slide
        void getUserInput(); //will wait for user input
    };
}; //namespace cli