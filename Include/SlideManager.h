#pragma once
#include "Slide.h"
#include "Storage.h"
#include "AttributeMutator.h"
#include "ItemInfo.h"
#include "SlideInfo.h"
#include "Mover.h"
#include "Slide_Factory.h"
#include "InvalidID_Cerr.h"

namespace edition {

    class SlideManager {
        public:
        using Location = document::A_Item::Location;
        using Design = cli::ItemInfo;
        using DesignerPtr = std::unique_ptr<AttributeMutator>;
        using MoverPtr = std::unique_ptr<Mover>;
        using SlideFactoryPtr = std::unique_ptr<edition::SlideFactory>;
        using ItemFactoryPtr = std::unique_ptr<edition::ItemFactory>;
        using ItemInfoPtr = std::shared_ptr<cli::ItemInfo>;
        using ItemPtr = std::shared_ptr<document::A_Item>;
        using SlidePtr = std::unique_ptr<document::Slide>;
        using SlideSharedPtr = std::shared_ptr<document::Slide>;
        using SlideInfoPtr = edition::SlideFactory::SlideInfoPtr;
        using Slide = document::Slide;
        using ID = size_t;

        public:
        SlideManager();
        ~SlideManager() = default;
        void removeItem(SlideSharedPtr, const ID);
        void addItem(SlideSharedPtr, ItemInfoPtr);
        void changeDesign(Slide&, const Design&, ID);
        SlidePtr CreateSlide(const SlideInfoPtr);

        private:
        DesignerPtr m_designer{nullptr};
        MoverPtr m_mover{nullptr};
    };

}; //namespace edition