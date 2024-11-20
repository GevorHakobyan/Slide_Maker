#pragma once
#include "Storage.h"
#include "SlideManager.h"

namespace edition {
    class StoreManager {
        using thisPtr = std::shared_ptr<StoreManager>;
        using StoragePtr = std::unique_ptr<document::Storage>;
        using ID = size_t;
        using Position = size_t;
        using BirthDate = size_t;
        using SlideInfo = cli::C_arguments;
        using ItemInfo = cli::C_arguments;
        using SlideManagerPtr = std::unique_ptr<SlideManager>;

        public:
        ~StoreManager() = default;
        static thisPtr getInstance();
        void addSlide(SlideInfo);
        void addItem(ItemInfo);
        void removeSlide(ID);
        void removeItem(ID, Position);
        void swapSlides(ID, ID);

        private:
        bool isPositionValid(size_t) const;
        bool isIdValid(size_t) const;
        StoreManager();

        private:
        SlideManagerPtr m_slideManager{nullptr};
        StoragePtr m_storage{nullptr};
        static thisPtr m_ptr;
    };
}; //namespace edition