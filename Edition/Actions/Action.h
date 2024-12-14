#pragma once
#include "SlideManager.h"
#include "Storage.h"
#include "Types.h"

namespace edition {
    class Action {
        public:
        using Info = cli::C_arguments;
        using ActionPtr = std::unique_ptr<Action>;
        using Actions = std::pair<ActionPtr, ActionPtr>;
        using StoragePtr = std::unique_ptr<document::Storage>;
        using SlideManagerPtr = std::unique_ptr<SlideManager>;

        public:
        Action();
        virtual Actions create(Info) = 0;
        virtual void Do() = 0;

        protected:
        static StoragePtr m_storage;
        static SlideManagerPtr m_slideManager;
    };
} //namespace edition