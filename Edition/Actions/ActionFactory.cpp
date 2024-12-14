#include "ActionFactory.h"

namespace edition {
    ActionFactory::Map ActionFactory::m_actions{};

    ActionFactory::ActionFactory() {
        m_actions["AddSlide"] = std::move(std::make_shared<AddSlide>());
        m_actions["AddItem"] = std::move(std::make_shared<AddItem>());
        m_actions["RemoveItem"] = std::move(std::make_shared<RemoveItem>());
        m_actions["RemoveSlide"] = std::move(std::make_shared<RemoveSlide>());
    }

    ActionFactory::Actions ActionFactory::create(const Info& info, ActionType type) {
        Actions answer;
        const auto DoPtr = m_actions.find(type)->second;
        auto [actionDo, undoType] = std::move(DoPtr->create(info));

        const auto UndoPtr = m_actions.find(undoType)->second;
        auto [actionUndo, undoType] = std::move(UndoPtr->create(info));

        answer.first = std::move(actionDo);
        answer.second = std::move(actionUndo);

        return std::move(answer);
    }
}