#pragma once
#include "ItemTypes.h"
#include "I_Attributes.h"

namespace cli {
    struct ItemInfo {
        using Type = edition::ItemType;
        using Length = document::I_Attributes::Length;
        using Width = document::I_Attributes::Width;
        using Color = document::I_Attributes::Color;

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