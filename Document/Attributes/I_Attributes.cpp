#include "I_Attributes.h"

document::I_Attributes::I_Attributes(Color color, const ID id) 
: _id{id}
{
    setColor(color);
};


document::I_Attributes::Color document::I_Attributes::getColor() const {
    return _itemColor;
}

void document::I_Attributes::setColor(Color color) {
    _itemColor = color;
}

document::I_Attributes::ID document::I_Attributes::getId() const {
    return _id;
}