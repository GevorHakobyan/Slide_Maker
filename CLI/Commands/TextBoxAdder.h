#pragma once
#include "TextBoxInfo.h"
#include "StoreManager.h"
#include "Command.h"

namespace cli {
    class TextBoxAdder : public I_Command {
        public:
        using BoxInfoPtr = std::shared_ptr<TextBoxInfo>;
        using BoxValues =  cli::C_options;

        public:
        TextBoxAdder(const Options&, const Arguments&);
        bool Execute() override;
        CommandPtr create(const ArgList&) override;

        private:
        void setBoxValues(const BoxValues&);

        private:
        BoxInfoPtr m_CommandInfo{nullptr};
    };
}; //namespace cli