#include "Action.h"

namespace edition {
    Action::SlideManagerPtr Action::m_slideManager{nullptr};
    Action::StoragePtr Action::m_storage{nullptr};

    Action::Action(const Info& info) {
        m_Data = info;
    }

    Action::Action() {
        m_slideManager = std::make_unique<SlideManager>();
        m_storage = std::make_unique<document::Storage>();
    }

    void Action::setData(const Info& info) {
        m_Data = info;
    }

    Action::SlidePtr Action::isSlideIdValid(size_t id) const {
        auto iter = m_storage->begin();

        if (iter == m_storage->end()) {
            throw InvalidID("Invalid Id", id, std::source_location::current());
        }

        while (iter != m_storage->end() && (*iter)->getId() != id) {
            ++iter;
        }
        
        if (iter == m_storage->end()) {
            return nullptr;
        }

        return *iter;
    }

    bool Action::isPositionValid(size_t pos) const {
        auto tmpPos = pos;
        auto iter = m_storage->begin();
        
        while (tmpPos > 0 && iter != m_storage->end()) {
            --tmpPos;
            ++iter;
        } 
        
        if (iter == m_storage->end() && pos != 0) {
            return false;
        }

        return true;
    }
}