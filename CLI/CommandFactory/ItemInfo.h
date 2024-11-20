#pragma once
#include "BoundingBox.h"
#include "ItemAttributes.h"
#include <memory>

namespace cli {
    struct ItemInfo {
        using AttributePtr = std::unique_ptr<ItemAttributes>;
        using BoundingBoxPtr = std::unique_ptr<document::Bounding_Box>;
        using Key = ItemAttributes::Key;
        using Value = ItemAttributes::Value;

        ItemInfo();
        void addAtribute(Key, Value);
        AttributePtr getAttributes();
        BoundingBoxPtr getBoundingBox();
        private:
        AttributePtr _attributes{nullptr};
        BoundingBoxPtr _boundingBox{nullptr};
    };
}; //namespace cli