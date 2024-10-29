#include "SlideMaker.h"

cli::Slide_Maker::Slide_Maker(const Options& opt, const Arguments& args)
: I_Command(opt, args), m_SlideInfo{std::make_shared<SlideInfo>()} {};

cli::Slide_Maker::Slide_Maker() 
: I_Command{}, m_SlideInfo{std::make_shared<SlideInfo>()} {};

bool cli::Slide_Maker::Execute() {
    auto StoreManagerPtr = edition::StoreManager::getInstance();
    StoreManagerPtr->addSlide(m_SlideInfo);
}

void cli::Slide_Maker::setSlideInfo(const SlideValues& values) {
    auto iter = values.cbegin();
    const auto title = std::get<std::string>(*iter);
    m_SlideInfo->setTitile(title);
    ++iter;

    if (values.end() != iter) {
        const auto text = std::get<std::string>(*iter);
        m_SlideInfo->setText(text);
    }
}

cli::I_Command::CommandPtr cli::Slide_Maker::create(const ArgList& Function_arguments) {
    const auto arguments = Function_arguments.getArgumetns();
    const auto options = Function_arguments.getOptions();

       try {
        validateInfo(options, arguments);
    } catch (const Exception& err) {
        throw;
    }

    setSlideInfo(arguments);
    return std::move(std::make_unique<cli::Slide_Maker>(options, arguments));
}

