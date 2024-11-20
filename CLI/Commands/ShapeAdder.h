#pragma once
#include "Command.h"

namespace cli{
    class ShapeAdder : public I_Command {
        public:
        ShapeAdder() = default;
        ShapeAdder(const Arguments&);
        CommandPtr create(const ArgList& args) override;
        bool Execute() override;
    };
}; //namespace cli