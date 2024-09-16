#pragma once
#include <vector>
#include "Item.h"

namespace document {

    //this will keep all the items available on slide
    class Slide {
        public: //usings
        using ItemList = std::vector<A_Item>;
        using Size = std::pair<size_t, size_t>;

        public: //methods
        Slide(std::initializer_list<A_Item>);
        Slide();
        ~Slide() = default;

        void addItem(const A_Item&);
        const A_Item& getItem(size_t) const;
        A_Item& getItem(size_t);
        bool resizeItem(size_t, Size);

        public:
        ItemList m_items{}; 
    };

} // namespace document
