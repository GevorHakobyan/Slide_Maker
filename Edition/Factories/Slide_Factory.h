#pragma once
#include "Slide.h"
#include "Item_Factory.h"

namespace edition {

    class SlideFactory {
        public:
        using Slide = document::Slide;
        using SlidePtr = std::unique_ptr<Slide>; 
        using Item_Factory = std::unique_ptr<ItemFactory>;
        using Data = document::Slide::Data;
        using SlideInfo = cli::C_arguments;

        public:
        static SlidePtr create(SlideInfo);

        private:
        SlideFactory() = default;

        private:
        static Item_Factory m_itemFactory;
        static int m_BirthId;
    };

}; //namespace edition