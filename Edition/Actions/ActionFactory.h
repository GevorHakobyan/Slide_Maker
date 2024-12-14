#pragma once
#include "AddItem.h"
#include "AddSlide.h"
#include "RemoveItem.h"
#include "RemoveSlide.h"

namespace edition {
    class ActionFactory {
        using ActionType = std::string;
        using S_ActionPtr = std::shared_ptr<Action>;
        using U_ActionPtr = std::unique_ptr<Action>;
        using Actions = std::pair<U_ActionPtr, U_ActionPtr>;
        using Map = std::unordered_map<ActionType, S_ActionPtr>;
        using Info = Action::Info;

        public:
        ActionFactory();
        static Actions create(const Info&, ActionType);
        private:
        static Map m_actions;
    };
}; //namespace edition