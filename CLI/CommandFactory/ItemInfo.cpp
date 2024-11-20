#include "ItemInfo.h"

cli::ItemInfo::Type cli::ItemInfo::getType() const {
    return _type;
}

const cli::ItemInfo::Color& cli::ItemInfo::getColor() const {
    return _color;
}

cli::ItemInfo::Length cli::ItemInfo::getLength() const {
    return _length;
}

cli::ItemInfo::Width cli::ItemInfo::getWidth() const {
    return _width;
}

void cli::ItemInfo::setColor(const Color& color) {
    _color = color;
}

void cli::ItemInfo::setLength(Length length) {
    _length = length;
}

void cli::ItemInfo::setType(Type type) {
    _type = type;
}

void cli::ItemInfo::setWidth(Width width) {
    _width = width;
}

