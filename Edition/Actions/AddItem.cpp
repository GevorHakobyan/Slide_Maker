#include "AddItem.h"

namespace edition {
    AddItem::AddItem(const Info& info)
    : Action(info) {};

    AddItem::Pair AddItem::create(const Info& info) {
        Pair answer;
        ActionPtr Do = std::make_unique<AddItem>(info);
        ActionType Undo = "RemoveItem";

        answer.first = std::move(Do);
        answer.second = Undo;

        return std::move(answer);
    }

    void AddItem::Do() {
        auto id = std::get<float>((*m_Data.find("oid")).second);
        const auto slidePtr = isSlideIdValid(id);

        if (nullptr == slidePtr) {
            throw InvalidID("Invalid ID", id, std::source_location::current());
        }
        
        m_slideManager->addItem(slidePtr, m_Data);
    }
}