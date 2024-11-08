#pragma once
#include "ItemInfo.h"
#include <string>

namespace cli {
    struct TextBoxInfo : public ItemInfo {
        using Content = std::string;
        using Owner = size_t;
        
        public:
        void setContent(const Content&);
        void setOwnerId(Owner);
        Owner getOwnerId() const;
        const Content& getContent() const;
        
        private:
        Owner m_OwnerID{0};
        Content _content{};
    };
};