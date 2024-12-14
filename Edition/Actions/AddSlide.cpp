#include "AddSlide.h"

namespace edition {
    AddSlide::AddSlide(const Info& info)
    :Action(info) {};

    AddSlide::Pair AddSlide::create(const Info& info) {
        Pair answer;
        ActionPtr Do = std::make_unique<AddSlide>(info);
        ActionType Undo = "RemoveSlide";

        answer.first = std::move(Do);
        answer.second = Undo;

        return std::move(answer);
    }

    void AddSlide::Do() {
        auto posIter = m_Data.find("ps");
        auto slidePtr = m_slideManager->CreateSlide(m_Data);

        if (m_Data.end() == posIter) {
            size_t position = (0 == m_storage->getSize()) ? 0 : m_storage->getSize() - 1;
            m_storage->insert(std::move(slidePtr), position);
            return;
        }
        
        auto pos = std::get_if<size_t>(&(*posIter).second);
        if (!isPositionValid(*pos)) {
            throw document::Invalid_Index("Invalid index", *pos, std::source_location::current());
        }

        m_storage->insert(std::move(slidePtr), *pos);
    }
}; //namespace edition