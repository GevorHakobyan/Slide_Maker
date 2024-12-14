#include "RemoveSlide.h"

namespace edition {
    RemoveSlide::RemoveSlide(const Info& info)
    : Action(info) {};

    RemoveSlide::Pair RemoveSlide::create(const Info& info) {
        Pair answer;
        ActionPtr Do = std::make_unique<RemoveSlide>(info);
        ActionType Undo = "AddSlide";

        answer.first = std::move(Do);
        answer.second = Undo;

        return std::move(answer);
    }

    void RemoveSlide::Do() {
        const auto posIter = m_Data.find("ps");
        if (posIter == m_Data.end()) {
            m_storage->erase(m_storage->getSize() - 1);
        }
    }
}