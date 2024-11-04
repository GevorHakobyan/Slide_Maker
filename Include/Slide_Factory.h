#pragma once
#include "../Include/Slide.h"
#include "../Include/SlideInfo.h"
#include "Slide_Factory.h"
#include "Item_Factory.h"
#include "ItemTypes.h"
#include "TextBoxInfo.h"

namespace edition {

    class SlideFactory {
        public:
        using Slide = document::Slide;
        using SlidePtr = std::unique_ptr<Slide>; 
        using SlideInfoPtr = std::shared_ptr<cli::SlideInfo>;
        using ItemFactory = std::unique_ptr<ItemFactory>;
        using Data = document::Slide::Data;
        using ItemType = edition::ItemType;
        using TextBoxInfo = cli::TextBoxInfo;

        public:
        static SlidePtr create(const SlideInfoPtr);

        private:
        SlideFactory() = default;

        private:
        static ItemFactory m_itemFactory;
        static int m_BirthId;
    };

}; //namespace edition