#include "StoreManager.h"

edition::StoreManager::thisPtr edition::StoreManager::m_ptr{nullptr};

edition::StoreManager::StoreManager()
: m_actionFactory{std::make_unique<ActionFactory>()} {};

  edition::StoreManager::thisPtr edition::StoreManager::getInstance() {
    if (nullptr == m_ptr) {
        m_ptr = std::shared_ptr<StoreManager>(new StoreManager());
    }

    return m_ptr;
  }

  void edition::StoreManager::push(ActionInfo info, ActionType type) {
    auto[Do, Undo] = std::move(m_actionFactory->create(info, type));
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
