#include "SlideManager.h"

edition::SlideManager::SlideManager()
: m_designer{nullptr}, m_mover{nullptr}
{
    m_designer = std::make_unique<AttributeMutator>();
    //initialize static classes values to use them
}


void edition::SlideManager::removeItem(SlideSharedPtr slidePtr, const ID id) {
    for(auto elem : *slidePtr) {
        if (id == elem->getId()) {
            slidePtr->erase(elem); 
            return;
        }
    }

    throw InvalidID("Invalid ID", id, std::source_location::current());
}

edition::SlideManager::SlidePtr edition::SlideManager::CreateSlide(SlideInfoPtr info) {
     return SlideFactory::create(info);
}

void edition::SlideManager::addItem(SlideSharedPtr slidePtr, ItemInfoPtr itemInfoPtr) {
    auto itemPtr = ItemFactory::create(*itemInfoPtr);
    slidePtr->insert(std::move(itemPtr));
}