#pragma once
#include <Types.h>

namespace document {
    struct I_Attributes {
        public:
        struct Color {
          float _red;
          float _green;
          float _blue;  
        };
        using ID = int;

        public:
        I_Attributes(Color, const ID);
        ~I_Attributes() = default;

        public:
        Color getColor() const;
        void setColor(Color);
        ID getId() const;

        protected:
        Color _itemColor{};
        const ID _id;
    };
}

//what if I have map with key enum
//Value std::variant<?, ?, ?>
//map[enum] = std::variant<>


