#pragma once

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


