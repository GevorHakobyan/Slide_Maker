#pragma once
#include <map>
#include "Command.h"
#include "StoreManager.h"
#include "InvalidCommand_Cerr.h"
#include "InvalidArgument_Cerr.h"
#include "CircleValidator.h"
#include "RectValidator.h"
#include "TriangleValidator.h"
#include "TextBoxValidator.h"

namespace cli{
    class ShapeAdder : public I_Command {
        public://usings
        using ValidatorPtr = std::shared_ptr<Validator>;
        using Map = std::map<std::string, ValidatorPtr>;
        public:
        ShapeAdder() = default;
        ShapeAdder(const Arguments&);
        CommandPtr create(const Arguments& args) override;
        bool Execute() override;
        static void addValue(const cli::option, const cli::argument);
        static void setValidators();
        private:
        void isInofAcceptable(const Arguments&) const;
        void isInfoComplete(const Arguments&) const;
        void validateInfo(const Arguments&, const Arguments&) const override;
        static Map m_Validators;
        static Arguments m_Valid_Info;
    };
}; //namespace cli