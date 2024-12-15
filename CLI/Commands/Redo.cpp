#include "Redo.h"

namespace cli {
    Redo::Arguments Redo::m_ValidInfo{};

    Redo::Redo(const Arguments& args)
    : I_Command{args} {};

    Redo::CommandPtr Redo::create(const Arguments& args) {
        validateInfo(args, m_ValidInfo);
        return std::move(std::make_unique<cli::Redo>(args));
    }

    bool Redo::Execute() {
        auto StoreMangerPtr = edition::StoreManager::getInstance();
        StoreMangerPtr->pop(false);
        return true;
    }

    void Redo::addValue(const cli::option& opt, cli::argument value) {
        m_ValidInfo[opt] = value;
    }

}; //namespace cli