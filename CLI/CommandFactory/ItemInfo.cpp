#include "ItemInfo.h"

namespace cli
{
    ItemInfo::ItemInfo() {
        _attributes = std::make_unique<ItemAttributes>();
        _boundingBox = std::make_unique<document::Bounding_Box>();
    }

    void ItemInfo::addAtribute(Key key, Value val) {
        _attributes->addAttribute(key, val);
    }

    ItemInfo::AttributePtr ItemInfo::getAttributes() {
        return std::move(_attributes);
    }

    ItemInfo::BoundingBoxPtr ItemInfo::getBoundingBox() {
        return std::move(_boundingBox);
    } 
} // namespace cli

