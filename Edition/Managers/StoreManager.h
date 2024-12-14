#pragma once
#include "Action.h"
#include <stack>

namespace edition {
    class StoreManager {
        using Stack = std::stack<std::unique_ptr<Action>>;
        using Map = std::unordered_map<std::string, std::shared_ptr<Action>>;
        using thisPtr = std::shared_ptr<StoreManager>;
        using StoragePtr = std::unique_ptr<document::Storage>;
        using ID = size_t;
        using Position = size_t;
        using BirthDate = size_t;
        using SlideInfo = cli::C_arguments;
        using ItemInfo = cli::C_arguments;
        using SlideManagerPtr = std::unique_ptr<SlideManager>;
        using ActionInfo = Action::Info;
        using ActionType = std::string;

        public:
        ~StoreManager() = default;
        static thisPtr getInstance();
        void push(ActionInfo, ActionType);
        void pop(bool = true);
        void addSlide(SlideInfo);
        void addItem(ItemInfo);
        void removeSlide(ID);
        void removeItem(ID, Position);
        void swapSlides(ID, ID);

        private:
        bool isPositionValid(size_t) const;
        bool isIdValid(size_t) const;
        void setActions();
        StoreManager();

        private:
        Stack m_undo{};
        Stack m_redo{};
        Map m_actions{};
        SlideManagerPtr m_slideManager{nullptr};
        StoragePtr m_storage{nullptr};
        static thisPtr m_ptr;
    };
}; //namespace edition