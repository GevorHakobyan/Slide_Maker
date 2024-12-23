#pragma once 
#include "Types.h"
#include "Slide.h"

namespace View {
    class ViewManager {
        public:
        using SlidePtr = std::shared_ptr<document::Slide>;
        public:
        void PrintSlide(SlidePtr) const;
        void PrintHelp(const std::string&) const;
    };
} //namespace View