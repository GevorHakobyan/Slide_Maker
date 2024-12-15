#include "Remover.h"

namespace cli {
    Remover::Arguments Remover::m_ValidInfo{};

    Remover::Remover(const Arguments& arguments)
    : I_Command{arguments} {};

    Remover::CommandPtr Remover::create(const Arguments& arguments) {
        validateInfo(arguments);
        return std::move(std::make_unique<Remover>(arguments));
    }

    bool Remover::Execute() {
        auto StoreManagerPtr = edition::StoreManager::getInstance();
        const auto objType = std::get<std::string>((*m_Arguments.find("obj")).second);
        const auto ActionType = (objType == "slide") ? "RemoveSlide" : "RemoveItem";
        StoreManagerPtr->push(std::move(m_Arguments), ActionType);
        return true;
    }

    void Remover::addValue(const cli::option& opt, cli::argument value) {
        m_ValidInfo[opt] = value;
    }

    void Remover::validateInfo(const Arguments& args) {
        isInfoAcceptable(args);
        isInfoComplete(args);
    }

    void Remover::isInfoAcceptable(const Arguments& args) {
        I_Command::validateInfo(args, m_ValidInfo);
    }

    void Remover::isInfoComplete(const Arguments& args) {
        const auto objIter = args.find("obj");
        if (objIter == args.end()) {
            throw InvalidCommand_Cerr("Removed type is missing", "Remover", std::source_location::current());
        }

        const auto slideId = args.find("sid");
        if (slideId == args.end()) {
            throw InvalidCommand_Cerr("Slide Id is missing", "Remover", std::source_location::current());
        }

        const auto objType = std::get<std::string>((*objIter).second);
        if (objType == "slide") {
            return;
        }

        const auto itemId = args.find("iid");
        if (itemId == args.end()) {
            throw InvalidCommand_Cerr("Item id is missing", "Remover", std::source_location::current());
        }
    }

}; //namespace cli