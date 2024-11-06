#pragma once
#include "Slide.h"
#include "SlideInfo.h"
#include "Item_Factory.h"
#include "TextBoxInfo.h"

namespace edition {

    class SlideFactory {
        public:
        using Slide = document::Slide;
        using SlidePtr = std::unique_ptr<Slide>; 
        using SlideInfoPtr = std::shared_ptr<cli::SlideInfo>;
        using Item_Factory = std::unique_ptr<ItemFactory>;
        using Data = document::Slide::Data;
        using ItemType = edition::ItemType;
        using TextBoxInfo = cli::TextBoxInfo;

        public:
        static SlidePtr create(const SlideInfoPtr);

        private:
        SlideFactory() = default;

        private:
        static Item_Factory m_itemFactory;
        static int m_BirthId;
    };

}; //namespace edition