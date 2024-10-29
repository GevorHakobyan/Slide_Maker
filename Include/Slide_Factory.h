#pragma once
#include "../Include/Slide.h"
#include "../CLI/CommandFactory/SlideInfo.h"

namespace edition {

    class SlideFactory {
        public:
        using Slide = document::Slide;
        using SlidePtr = std::unique_ptr<Slide>; 
        using SlideInfoPtr = std::shared_ptr<cli::SlideInfo>;

        public:
        static SlidePtr create(const SlideInfoPtr);

        private:
        SlideFactory() = default;
    };

}; //namespace edition