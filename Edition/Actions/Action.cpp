#include "Action.h"

namespace edition {
    Action::SlideManagerPtr Action::m_slideManager{nullptr};
    Action::StoragePtr Action::m_storage{nullptr};

    Action::Action() {
        m_slideManager = std::make_unique<SlideManager>();
        m_storage = std::make_unique<document::Storage>();
    }
}