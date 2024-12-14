#include "StoreManager.h"

edition::StoreManager::thisPtr edition::StoreManager::m_ptr{nullptr};

edition::StoreManager::StoreManager()
: m_slideManager{std::make_unique<SlideManager>()}, 
  m_storage{std::make_unique<document::Storage>()}
  {}

  edition::StoreManager::thisPtr edition::StoreManager::getInstance() {
    if (nullptr == m_ptr) {
        m_ptr = std::shared_ptr<StoreManager>(new StoreManager());
        m_ptr->setActions();
    }

    return m_ptr;
  }

  void edition::StoreManager::push(ActionInfo info, ActionType type) {
    const auto actionPtr = m_actions[type];
    const auto[Do, Undo] = std::move(actionPtr->create(info));
    Do->Do();

    m_undo.push(std::move(Undo));
    m_redo.push(std::move(Do));
  }

  void edition::StoreManager::pop(bool undo) {
    if (undo) {
      m_undo.top()->Do();
      m_undo.pop();
      return;
    }

    if (m_redo.size() > m_undo.size()) {
      m_redo.top()->Do();
      m_redo.pop();
    }
  }

void edition::StoreManager::addSlide(SlideInfo info) {
  auto posIter = info.find("ps");
  auto slidePtr = m_slideManager->CreateSlide(info);

  if (info.end() == posIter) {
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

void edition::StoreManager::addItem(const ItemInfo info) {
  auto iter = m_storage->begin();
  auto id = std::get<float>((*info.find("oid")).second);

  if (!isIdValid(id)) {
    throw InvalidID("Invalid ID", id, std::source_location::current());
  }
  
   while (iter != m_storage->end() && (*iter)->getId() != static_cast<size_t>(id)) {
    ++iter;
  }
  
  m_slideManager->addItem(*iter, info);
}

bool edition::StoreManager::isPositionValid(size_t pos) const {
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

bool edition::StoreManager::isIdValid(size_t id) const {
  auto iter = m_storage->begin();

  if (iter == m_storage->end()) {
    throw InvalidID("Invalid Id", id, std::source_location::current());
  }

  while (iter != m_storage->end() && (*iter)->getId() != id) {
    ++iter;
  }
  
  if (iter == m_storage->end()) {
    return false;
  }

  return true;  
}