#pragma once

struct I_Attributes {
    enum class Color{Red, Green, Black};
    using Length  = float;
    using Width = float;
    public:
    Color _itemColor{Color::Red};
    Length _itemLength{0.0};
    Width _itemWidth{0.0};
};
