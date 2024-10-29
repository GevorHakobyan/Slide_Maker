#include "../Include/SlideManager.h"

edition::SlideManager::SlideManager()
: m_designer{nullptr}, m_mover{nullptr} 
{
    m_designer = std::make_unique<AttributeMutator>();
}


void edition::SlideManager::removeItem(Slide& slide, const ID id) {
    ItemPtr ptr{nullptr};
    for(auto elem : slide) {
        if (id == elem->getId()) {
            ptr = elem;
        }
    }
}

