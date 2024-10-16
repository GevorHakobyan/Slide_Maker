#include "../Include/I_Attributes.h"

document::I_Attributes::I_Attributes(Color color, Length len, Width width) {
    setColor(color);
    setLentgth(len);
    setWidth(width);
};

document::I_Attributes::Color document::I_Attributes::getColor() const {
    return _itemColor;
}

document::I_Attributes::Length document::I_Attributes::getLength() const {
    return _itemLength;
}

document::I_Attributes::Width document::I_Attributes::getWidth() const {
    return _itemWidth;
}

void document::I_Attributes::setColor(Color color) {
    _itemColor = color;
}

void document::I_Attributes::setLentgth(Length length) {
    _itemLength = length;
}

void document::I_Attributes::setWidth(Width width) {
    _itemWidth = width;
}