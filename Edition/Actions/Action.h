#pragma once
#include "SlideManager.h"
#include "Storage.h"
#include "Types.h"

namespace edition {
    class Action {
        public:
        using Info = cli::C_arguments;
        using ActionPtr = std::unique_ptr<Action>;
        using ActionType = std::string;
        using Pair = std::pair<ActionPtr, ActionType>;
        using SlidePtr = std::shared_ptr<document::Slide>;
        using StoragePtr = std::unique_ptr<document::Storage>;
        using SlideManagerPtr = std::unique_ptr<SlideManager>;

        public:
        Action();
        Action(const Info&);
        virtual Pair create(const Info&) = 0;
        virtual void Do() = 0;

        protected:
        void setData(const Info&);
        SlidePtr isSlideIdValid(size_t) const;
        bool isPositionValid(size_t) const;

        protected:
        Info m_Data;
        static StoragePtr m_storage;
        static SlideManagerPtr m_slideManager;
    };
} //namespace edition