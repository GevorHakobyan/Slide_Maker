#include "StoreManager.h"

edition::StoreManager::thisPtr edition::StoreManager::m_ptr{nullptr};

edition::StoreManager::StoreManager()
: m_slideManager{std::make_unique<SlideManager>()}, 
  m_storage{std::make_unique<document::Storage>()}
  {}

  edition::StoreManager::thisPtr edition::StoreManager::getInstance() {
    if (nullptr == m_ptr) {
        m_ptr = std::shared_ptr<StoreManager>(new StoreManager());
    }

    return m_ptr;
  }

void edition::StoreManager::addSlide(const SlideInfoPtr info, Position pos) {
  auto slidePtr = m_slideManager->CreateSlide(info);
  auto iter = m_storage->begin();
  auto tmpPos = pos;

  while (tmpPos > 0 && iter != m_storage->end()) {
    --tmpPos;
    ++iter;
  } 

  if (iter == m_storage->end() && pos != 0) {
    throw document::Invalid_Index("Invalid index", pos, std::source_location::current());
  }

  m_storage->insert(std::move(slidePtr), pos);
}

void edition::StoreManager::addItem(const ItemInfoPtr info, ID  id) {
  auto iter = m_storage->begin();

  while ((*iter)->getId() != id || iter != m_storage->end()) {
    ++iter;
  }
  
  if (iter == m_storage->end()) {
    throw InvalidID("Invalid ID", id, std::source_location::current());
  }

  m_slideManager->addItem(*iter, info);
}
