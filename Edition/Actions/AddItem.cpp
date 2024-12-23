#include "AddItem.h"

namespace edition {
    AddItem::AddItem(const Info& info)
    : Action(info) {};

    AddItem::Pair AddItem::create(Info& info) {
        Pair answer;
        ActionPtr Do = std::make_unique<AddItem>(info);
        ActionType Undo = "RemoveItem";
        Do->Do();
        info["iid"] = dynamic_cast<AddItem*>(Do.get())->getItemId();

        answer.first = std::move(Do);
        answer.second = Undo;

        return std::move(answer);
    }

    void AddItem::Do() {
        auto sid = std::get<float>((*m_Data.find("oid")).second);
        const auto slidePtr = isSlideIdValid(sid);

        if (nullptr == slidePtr) {
            throw InvalidID("Invalid ID", sid, std::source_location::current());
        }
        
       float iid = m_slideManager->addItem(slidePtr, m_Data);
       m_ItemId = iid;
    }

    AddItem::ID AddItem::getItemId() const {
        return m_ItemId;
    }
}
