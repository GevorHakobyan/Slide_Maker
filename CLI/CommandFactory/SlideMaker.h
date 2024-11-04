#pragma once
#include "Command.h"
#include "../Include/SlideInfo.h"
#include "../Include/StoreManager.h"

namespace cli {
    class Slide_Maker : public I_Command {
        public:
        using SlideInfoPtr = std::shared_ptr<SlideInfo>;
        using SlideValues = cli::C_options;
        public:
        Slide_Maker();
        Slide_Maker(const Options&, const Arguments&);
        bool Execute() override;
        CommandPtr create(const ArgList&) override;
        private:
        void setSlideInfo(const SlideValues&);

        private:
        SlideInfoPtr m_SlideInfo{nullptr};
    };
} //namespace cli