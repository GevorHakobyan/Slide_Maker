#pragma once
#include "InvalidIndex_Cerr.h"
#include <vector>
#include "Item.h"

namespace document {

    class Slide {
       private:
       class Iterator;
       class ConstIterator;
       public:
       using ItemPtr = std::shared_ptr<A_Item>;
       using ID = size_t;
       using Data = std::vector<ItemPtr>;
       using Index = size_t;
       using Size = size_t;

       public:
       Slide(Data&&, const ID);
       ~Slide() = default;
       Slide(Slide&&) noexcept;
       Slide& operator=(Slide&&) noexcept;
       Slide(const Slide&) noexcept;
       Slide& operator=(const Slide&) noexcept;
       friend bool operator==(const Slide&, const Slide&);
       friend void Swap(Slide&, Slide&) noexcept;

       Size getItemCount() const;  
       ID getId() const;
       void erase(ItemPtr);
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
        using IterPointer = std::shared_ptr<PointerType>;

        public:
        Iterator(size_t, Data&);
        Iterator operator++();
        Iterator& operator++(int);
        ValueType operator*();
        IterPointer  operator->();
        const ValueType operator*() const;
        const IterPointer operator->() const;
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);

        private:
        Iterator(IterPointer);
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
        using IterPointer = std::shared_ptr<Data::const_iterator>;

        public:
        ConstIterator(size_t, const Data&);
        ConstIterator operator++();
        ConstIterator& operator++(int);
        ValueType operator*();
        IterPointer operator->();
        const ValueType operator*() const;
        const IterPointer operator->() const;
        bool operator==(const ConstIterator&);
        bool operator!=(const ConstIterator&);

        private:
        ConstIterator(IterPointer);
        bool isIndexValid(size_t, size_t) const;
        void setIterator(size_t, const Data&);

        private:
        IterPointer m_iterator{nullptr};
       };
     

       private:
       void assignInfo(const Slide&);
       bool isIndexValid(Index) const;
       
       private:
       const ID m_id{};
       Data m_data{};
       Size m_dataSize{};
    };
} // namespace document

