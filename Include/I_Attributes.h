#pragma once

namespace document {
    struct I_Attributes {
        public:
        struct Color {
          float _red;
          float _green;
          float _blue;  
        };
        using Length  = float;
        using Width = float;
        using ID = int;

        public:
        I_Attributes(Color, Length, Width, const ID);
        ~I_Attributes() = default;

        public:
        Color getColor() const;
        Length getLength() const;
        Width getWidth() const;
        void setColor(Color);
        void setLentgth(Length);
        void setWidth(Width);

        protected:
        Color _itemColor{};
        Length _itemLength{0.0};
        Width _itemWidth{0.0};
        const ID _id;
    };
}
