#include "SlideManager.h"

edition::SlideManager::SlideManager()
: m_mover{nullptr} {}


void edition::SlideManager::removeItem(SlideSharedPtr slidePtr, ItemPtr item) {
    slidePtr->erase(item);
}

edition::SlideManager::SlidePtr edition::SlideManager::CreateSlide(SlideInfo info) {
     return SlideFactory::create(info);
}

void edition::SlideManager::addItem(SlideSharedPtr slidePtr, ItemInfo itemInfo) {
    auto itemPtr = ItemFactory::create(itemInfo);
    slidePtr->insert(std::move(itemPtr));
}