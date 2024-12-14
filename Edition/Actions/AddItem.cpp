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
        auto iter = m_storage->begin();
        auto id = std::get<float>((*m_Data.find("oid")).second);

        if (!isSlideIdValid(id)) {
            throw InvalidID("Invalid ID", id, std::source_location::current());
        }
        
        while (iter != m_storage->end() && (*iter)->getId() != static_cast<size_t>(id)) {
            ++iter;
        }
        
        m_slideManager->addItem(*iter, m_Data);
    }
}