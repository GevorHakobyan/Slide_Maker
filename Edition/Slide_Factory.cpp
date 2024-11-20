#include "Slide_Factory.h"

edition::SlideFactory::Item_Factory edition::SlideFactory::m_itemFactory{nullptr};
int edition::SlideFactory::m_BirthId{0};

edition::SlideFactory::SlidePtr edition::SlideFactory::create(SlideInfoPtr info) {
    Data items;
    const auto title = info->getTitle();
    const auto text = info->getText();

    /*if (title.has_value()) {
        TextBoxInfo info;
        info.setType(ItemType::TextBox);
        info.setContent(title.value());
        items.push_back(m_itemFactory->create(info));
    }

    if (text.has_value()) {
        TextBoxInfo info;
        info.setType(ItemType::TextBox);
        info.setContent(text.value());
        items.push_back(m_itemFactory->create(info));
    }*/

    ++m_BirthId;
    return std::move(std::make_unique<Slide>(std::move(items), m_BirthId));
}