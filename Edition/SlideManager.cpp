#include "SlideManager.h"

edition::SlideManager::SlideManager()
: m_designer{nullptr}, m_mover{nullptr}, m_factory{nullptr}
{
    m_designer = std::make_unique<AttributeMutator>();
}


void edition::SlideManager::removeItem(Slide& slide, const ID id) {
    for(auto elem : slide) {
        if (id == elem->getId()) {
            slide.erase(elem); 
            return;
        }
    }

    //throw Invalid ID
}

edition::SlideManager::SlidePtr edition::SlideManager::CreateSlide(SlideInfoPtr info) {
     return m_factory->create(info);
}