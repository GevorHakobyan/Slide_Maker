#include "ViewManager.h"
#include <iostream>

namespace View {

    void ViewManager::PrintHelp(const std::string& option) const {
        std::cout << "Help\n";
        return;
    }


    void ViewManager::PrintSlide(SlidePtr slide) const {
        std::cout << "Printing slide\n";
        return;
    }
    
}