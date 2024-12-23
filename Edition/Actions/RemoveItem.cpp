#include "RemoveItem.h"

namespace edition {
    RemoveItem::RemoveItem(const Info& info)
    : Action{info} {};

    RemoveItem::Pair RemoveItem::create(Info& info) {
        Pair answer;
        ActionPtr Do = std::make_unique<RemoveItem>(info);
        ActionType Undo = "AddItem";

        answer.first = std::move(Do);
        answer.second = Undo;

        return std::move(answer);
    }

    void RemoveItem::Do() {
        const auto slideId = std::get<float>((*m_Data.find("oid")).second);
        const auto itemId = std::get<float>((*m_Data.find("iid")).second);

        const auto slidePtr = isSlideIdValid(slideId);
        const auto itemPtr = isItemIdValid(slidePtr, itemId);

        if (nullptr == slidePtr) {
            throw InvalidID("Invalid Slide Id", slideId, std::source_location::current());
        }

        if (nullptr == itemPtr) {
            throw InvalidID("Invalid Item id", itemId, std::source_location::current());
        }
        m_slideManager->removeItem(slidePtr, itemPtr);
    }

    RemoveItem::ItemPtr RemoveItem::isItemIdValid(SlidePtr slide, size_t itemId) const {
        for (const auto& item : *slide) {
            if (item->getId() == itemId) {
                return item;
            }
        }
        return nullptr;
    }
}; //namespace edition