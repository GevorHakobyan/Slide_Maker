#include "SlideManager.h"

edition::SlideManager::SlideManager()
: m_mover{nullptr} {}


void edition::SlideManager::removeItem(SlideSharedPtr slidePtr, const ID id) {
    for(auto elem : *slidePtr) {
        if (id == elem->getId()) {
            slidePtr->erase(elem); 
            return;
        }
    }

    throw InvalidID("Invalid ID", id, std::source_location::current());
}

edition::SlideManager::SlidePtr edition::SlideManager::CreateSlide(SlideInfo info) {
     return SlideFactory::create(info);
}

void edition::SlideManager::addItem(SlideSharedPtr slidePtr, ItemInfo itemInfo) {
    auto itemPtr = ItemFactory::create(itemInfo);
    slidePtr->insert(std::move(itemPtr));
}