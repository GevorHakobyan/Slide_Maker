#include "Rectangle.h"

namespace document {
    Rectangle::Rectangle(AttributePtr attributes) 
    : A_Item{std::move(attributes)} {};

    Rectangle::ItemPtr Rectangle::create(AttributePtr attributes) {
        return std::move(std::make_unique<Rectangle>(attributes));
    }
    
}; //namespace document