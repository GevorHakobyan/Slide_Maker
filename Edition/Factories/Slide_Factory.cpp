#include "Slide_Factory.h"

edition::SlideFactory::Item_Factory edition::SlideFactory::m_itemFactory{nullptr};
int edition::SlideFactory::m_BirthId{1};

edition::SlideFactory::SlidePtr edition::SlideFactory::create(SlideInfo info) {
    Data items;
    const auto title = info.find("tit");
    const auto content = info.find("ct");

    if (title != info.end()) {
        cli::C_arguments itemInfo;
        itemInfo["t"] = "tb";
        itemInfo["tit"] = (*title).second;
        itemInfo["lc"] = std::move((std::pair<int, int>(0, 0)));
        auto textBox = m_itemFactory->create(std::move(itemInfo));
        items.push_back(std::move(textBox));
    }

    if (content != info.end()) {
        cli::C_arguments itemInfo;
        itemInfo["t"] = "tb";
        itemInfo["ct"] = (*content).second;
        itemInfo["lc"] = std::move(std::pair<int, int>(1, 1));
        auto textBox = m_itemFactory->create(std::move(itemInfo));
        items.push_back(std::move(textBox));
    }

    ++m_BirthId;
    return std::move(std::make_unique<Slide>(std::move(items), m_BirthId));
}