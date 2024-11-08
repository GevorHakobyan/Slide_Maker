#include "TextBoxAdder.h"

cli::TextBoxAdder::TextBoxAdder(const Options& options, const Arguments& arguments)
: I_Command(options, arguments), m_CommandInfo{std::make_shared<TextBoxInfo>()} {};


bool cli::TextBoxAdder::Execute() {
    auto StoreManager = edition::StoreManager::getInstance();
    StoreManager->addItem(m_CommandInfo, 3);
}

cli::I_Command::CommandPtr cli::TextBoxAdder::create(const ArgList& arguments) {
    const auto options = arguments.getOptions();
    const auto values = arguments.getArgumetns();

    validateInfo(options, values);
    setBoxValues(values);

    return std::move(std::make_unique<TextBoxAdder>(options, values));
}

void cli::TextBoxAdder::setBoxValues(const BoxValues& values) {
    auto iter = values.begin();
    const auto content = std::get<std::string>(*iter);

    ++iter;
    const auto id = std::get<size_t>(*iter);
    
    m_CommandInfo->setContent(content);
    m_CommandInfo->setOwnerId(id);
}