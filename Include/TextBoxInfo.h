#pragma once
#include "ItemInfo.h"
#include <string>

namespace cli {
    struct TextBoxInfo : public ItemInfo {
        using Content = std::string;
        
        public:
        void setContent(const Content&);
        const Content& getContent() const;
        
        private:
        Content _content{};
    };
};