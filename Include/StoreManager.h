#pragma once
#include "Storage.h"
#include "ItemInfo.h"
#include "SlideManager.h"

namespace edition {
    class StoreManager {
        using thisPtr = std::shared_ptr<StoreManager>;
        using StoragePtr = std::unique_ptr<document::Storage>;
        using ID = int;
        using Position = size_t;
        using BirthDate = size_t;
        using SlideInfoPtr = std::shared_ptr<cli::SlideInfo>;
        using ItemInfoPtr = std::shared_ptr<cli::ItemInfo>;
        using SlideManagerPtr = std::unique_ptr<SlideManager>;

        public:
        ~StoreManager() = default;
        static thisPtr getInstance();
        void addSlide(const SlideInfoPtr, Position = 0);
        void addItem(const ItemInfoPtr, ID);
        void removeSlide(ID);
        void removeItem(ID, Position);
        void swapSlides(ID, ID);

        private:
        StoreManager();

        private:
        SlideManagerPtr m_slideManager{nullptr};
        StoragePtr m_storage{nullptr};
        static thisPtr m_ptr;
    };
}; //namespace edition