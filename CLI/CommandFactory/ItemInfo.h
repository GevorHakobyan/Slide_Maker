#pragma once
#include "ItemTypes.h"
#include "BoundingBox.h"
#include "I_Attributes.h"

namespace cli {
    struct ItemInfo {
        using Type = edition::ItemType;
        using Length = document::Bounding_Box::Length;
        using Width = document::Bounding_Box::Width;
        using Color = document::I_Attributes::Color;

        ItemInfo() = default;
        virtual ~ItemInfo() = default;
        Type getType() const;
        Length getLength() const;
        Width getWidth() const;
        const Color& getColor() const;
        
        void setType(Type);
        void setLength(Length);
        void setWidth(Width);
        void setColor(const Color&);

        protected:
        Length _length;
        Width _width;
        Color _color;
        Type _type;
    };
}; //namespace cli