#include "Undo.h"

namespace cli {
    Undo::Arguments Undo::m_ValidInfo{};

    Undo::Undo(const Arguments& args)
    : I_Command{args} {};

    Undo::CommandPtr Undo::create(const Arguments& args) {
        validateInfo(args, m_ValidInfo);
        return std::move(std::make_unique<cli::Undo>(args));
    }

    bool Undo::Execute() {
        auto StoreMangerPtr = edition::StoreManager::getInstance();
        StoreMangerPtr->pop(true);
        return true;
    }

    void Undo::addValue(const cli::option& opt, cli::argument value) {
        m_ValidInfo[opt] = value;
    }
}; //namespace cli