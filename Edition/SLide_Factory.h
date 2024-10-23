#pragma once
#include "../Document/document/Slide.h"
#include "../CLI/CommandFactory/SlideInfo.h"

namespace edition {

    class SlideFactory {
        public:
        using SlideInfo = cli::SlideInfo;
        using Slide = document::Slide;

        public:
        static Slide create(const SlideInfo&);

        private:
        SlideFactory() = default;
    };

}; //namespace edition