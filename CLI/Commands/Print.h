#pragma once
#include "Command.h"
#include "Validator.h"
#include "StoreManager.h"
#include "InvalidCommand_Cerr.h"
#include "SlidePrintValidator.h"
#include "HelpPrintValidator.h"
#include <map>

namespace cli {
    class Print : public I_Command {
        public://usings
        using ValidatorPtr = std::shared_ptr<Validator>;
        using Map = std::map<std::string, ValidatorPtr>;
        public:
        Print() = default;
        Print(const Arguments&);
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
}; //namesapce cli