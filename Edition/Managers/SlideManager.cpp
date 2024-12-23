#include "SlideManager.h"

edition::SlideManager::SlideManager()
: m_mover{nullptr} {}


edition::SlideManager::ID edition::SlideManager::removeItem(SlideSharedPtr slidePtr, ItemPtr item) {
    const auto id = item->getId();
    slidePtr->erase(item);
    return id;
}

edition::SlideManager::SlidePtr edition::SlideManager::CreateSlide(SlideInfo info) {
     return SlideFactory::create(info);
}

edition::SlideManager::ID edition::SlideManager::addItem(SlideSharedPtr slidePtr, ItemInfo itemInfo) {
    auto itemPtr = ItemFactory::create(itemInfo);
    const auto id = itemPtr->getId();
    slidePtr->insert(std::move(itemPtr));
    return id;
}