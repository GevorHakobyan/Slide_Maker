#pragma once
#include "Command.h"
#include "StoreManager.h"

namespace cli{
    class ShapeAdder : public I_Command {
        public:
        ShapeAdder() = default;
        ShapeAdder(const Arguments&);
        CommandPtr create(const Arguments& args) override;
        bool Execute() override;
    };
}; //namespace cli