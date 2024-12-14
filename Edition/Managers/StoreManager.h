#pragma once
#include "ActionFactory.h"
#include <stack>

namespace edition {
    class StoreManager {
        using Stack = std::stack<std::unique_ptr<Action>>;
        using thisPtr = std::shared_ptr<StoreManager>;
        using ActionInfo = Action::Info;
        using ActionType = std::string;
        using FactoryPtr = std::unique_ptr<ActionFactory>;

        public:
        ~StoreManager() = default;
        static thisPtr getInstance();
        void push(ActionInfo, ActionType);
        void pop(bool = true);

        private:
        StoreManager();

        private:
        Stack m_undo{};
        Stack m_redo{};
        FactoryPtr m_actionFactory{nullptr};
        static thisPtr m_ptr;
    };
}; //namespace edition