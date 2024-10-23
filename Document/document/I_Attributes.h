#pragma once

namespace document {
    struct I_Attributes {
        enum class Color{Red, Green, Black};
        using Length  = float;
        using Width = float;
        public:
        I_Attributes(Color, Length, Width);
        ~I_Attributes() = default;

        public:
        Color getColor() const;
        Length getLength() const;
        Width getWidth() const;
        void setColor(Color);
        void setLentgth(Length);
        void setWidth(Width);

        public:
        Color _itemColor{Color::Red};
        Length _itemLength{0.0};
        Width _itemWidth{0.0};
    };
}
