#pragma once

#include <memory>
#include <vector>
#include "../Include/Item.h"
#include "../Include/I_Attributes.h"
#include "../Include/Slide.h"
#include "Item_Info.h"

namespace edition {

    class Adder {
        public:
        using Info = document::Item_Info;

        public:
        virtual void add(const Info&) = 0;
    };

}; //namespace edition


/*
FRIST: INTERFACE MUST BE:
Who will create -> every command should have access, therefore must be SINGELTON.

INTERFACE:
    1.AddSLide(Title, color);
    2. RemoveSlide(Index);
    3. AddShape(Index, Type);
    4.RemoveShape(Index of slide, index of shape);

BACK: how?
    Need an iterator of Storage, for 1 - 2;
    Need an iterator of Slide, for 2 - 3;
*/