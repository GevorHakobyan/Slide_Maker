#include "../Include/StoreManager.h"

edition::StoreManager::thisPtr edition::StoreManager::m_ptr{nullptr};

edition::StoreManager::StoreManager()
: m_manager{std::make_unique<SlideManager>()}, 
  m_storage{std::make_unique<document::Storage>()},
  m_date{0} {}

  edition::StoreManager::thisPtr edition::StoreManager::getInstance() {
    if (nullptr == m_ptr) {
        m_ptr = std::make_shared<StoreManager>();
    }

    return m_ptr;
  }

