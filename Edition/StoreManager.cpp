#include "StoreManager.h"

edition::StoreManager::thisPtr edition::StoreManager::m_ptr{nullptr};

edition::StoreManager::StoreManager()
: m_slideManager{std::make_unique<SlideManager>()}, 
  m_storage{std::make_unique<document::Storage>()},
  m_date{0} {}

  edition::StoreManager::thisPtr edition::StoreManager::getInstance() {
    if (nullptr == m_ptr) {
        m_ptr = std::shared_ptr<StoreManager>(new StoreManager());
    }

    return m_ptr;
  }

void edition::StoreManager::addSlide(const SlideInfoPtr info, Position pos) {
  const auto slidePtr = m_slideManager->CreateSlide(info);
  auto iter = m_storage->begin();

  while (pos > 0 || iter != m_storage->end()) {
    ++iter;
  }

  
}
