#pragma once
#include "Slide.h"
#include "Storage.h"
#include "Mover.h"
#include "Slide_Factory.h"
#include "InvalidID_Cerr.h"

namespace edition {

    class SlideManager {
        public:
        using Location = document::A_Item::Location;
        using Design = cli::C_arguments;
        using MoverPtr = std::unique_ptr<Mover>;
        using SlideFactoryPtr = std::unique_ptr<edition::SlideFactory>;
        using ItemFactoryPtr = std::unique_ptr<edition::ItemFactory>;
        using ItemInfo = cli::C_arguments;
        using ItemPtr = std::shared_ptr<document::A_Item>;
        using SlidePtr = std::unique_ptr<document::Slide>;
        using SlideSharedPtr = std::shared_ptr<document::Slide>;
        using SlideInfo = cli::C_arguments;
        using Slide = document::Slide;
        using ID = int;

        public:
        SlideManager();
        ~SlideManager() = default;
        void removeItem(SlideSharedPtr, const ID);
        void addItem(SlideSharedPtr, ItemInfo);
        void changeDesign(Slide&, const Design&, ID);
        SlidePtr CreateSlide(const SlideInfo);

        private:
        MoverPtr m_mover{nullptr};
    };

}; //namespace edition