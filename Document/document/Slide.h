#pragma once
#include <vector>
#include "InvalidIndex_Cerr.h"
#include "Item.h"

namespace document {

    class Slide {
       private:
       class Iterator;
       class ConstIterator;
       public:
       using ItemPtr = std::shared_ptr<A_Item>;
       using Data = std::vector<ItemPtr>;
       using Index = size_t;
       using Size = size_t;

       public:
       Slide(Data&);
       ~Slide() = default;
       Slide(Slide&&) noexcept;
       Slide& operator=(Slide&&) noexcept;
       Slide(const Slide&) noexcept;
       Slide& operator=(const Slide&) noexcept;
       friend bool operator==(const Slide&, const Slide&);
       friend void Swap(Slide&, Slide&) noexcept;

       Size getItemCount() const;  
       Iterator begin();
       Iterator end();
       ConstIterator cbegin() const;
       ConstIterator cend() const;
       
       private:
       class Iterator {
        public: //usings
        using Category = std::forward_iterator_tag;
        using ValueType = ItemPtr;
        using PointerType = Data::iterator;
        using IterPointer = PointerType;

        public:
        Iterator(size_t, Data&);
        Iterator operator++();
        Iterator& operator++(int);
        ValueType operator*();
        Iterator&  operator->();

        private:
        Iterator(PointerType);
        bool isIndexValid(size_t, size_t) const;
        void setIterator(size_t, Data&);

        private:
        IterPointer m_iterator{nullptr};
       };

       class ConstIterator {
        public: //usings
        using Category = std::forward_iterator_tag;
        using ValueType = ItemPtr;
        using PointerType = Data::const_iterator;
        using IterPointer = Data::const_iterator;

        public:
        ConstIterator(size_t, const Data&);
        ConstIterator operator++();
        ConstIterator& operator++(int);
        ValueType operator*();
        ConstIterator& operator->();

        private:
        ConstIterator(PointerType);
        bool isIndexValid(size_t, size_t) const;
        void setIterator(size_t, const Data&);

        private:
        IterPointer m_iterator{nullptr};
       };
     

       private:
       void assignInfo(const Slide&);
       bool isIndexValid(Index) const;
       
       private:
       Data m_data{};
       Size m_dataSize{};
    };
} // namespace document

