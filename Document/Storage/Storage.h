#pragma once
#include "Slide.h"
#include "InvalidIndex_Cerr.h"
#include <vector>
#include <memory>

namespace document {
    class Storage {
        public:
        class iterator;
        class const_iterator;
        public:
        using thisPtr = std::shared_ptr<Storage>;
        using SlidePtr = std::shared_ptr<Slide>;
        using SlideUptr = std::unique_ptr<Slide>;
        using ID = size_t;
        using Data = std::vector<SlidePtr>;
        using Index = size_t;
        using Size = size_t;
        using Position = size_t;

        public:
        ~Storage() = default;
        iterator begin();
        iterator end();
        void insert(SlideUptr, Position);
        void erase(const Position);
        Size getSize() const;
        const_iterator cbegin() const;
        const_iterator cend() const;


        private:
        bool isIndexValid(Index) const;

        public:
        class iterator {
            public: //usings
            using Category = std::bidirectional_iterator_tag;
            using ValueType = SlidePtr;
            using PointerType = Data::iterator;
            using IterPointer = std::shared_ptr<PointerType>;

            public:
            iterator(size_t, Data&);
            iterator operator++();
            iterator& operator++(int);
            iterator operator--();
            iterator& operator--(int);
            ValueType operator*();
            const ValueType operator*() const;
            const PointerType operator->() const;
            PointerType  operator->();
            friend bool operator==(const iterator&, const iterator&);
            friend bool operator!=(const iterator&, const iterator&);

            private:
            iterator(IterPointer);
            bool isIndexValid(size_t, size_t) const;
            void setIterator(size_t, Data&);

            private:
            IterPointer m_Iterator{nullptr};
        };

        class const_iterator {
            public: //usings
            using Category = std::random_access_iterator_tag;
            using ValueType = SlidePtr;
            using PointerType = Data::const_iterator;
            using IterPointer = std::shared_ptr<PointerType>;

            public:
            const_iterator(size_t, const Data&);
            const_iterator operator++();
            const_iterator& operator++(int);
            const_iterator operator--();
            const_iterator& operator--(int);
            ValueType operator*();
            PointerType  operator->();
            const ValueType operator*() const;
            const PointerType operator->() const;
            friend bool operator==(const const_iterator&, const const_iterator&);
            friend bool operator!=(const const_iterator&, const const_iterator&);

            private:
            const_iterator(IterPointer);
            bool isIndexValid(size_t, size_t) const;
            void setIterator(size_t, const Data&);

            private:
            IterPointer m_iterator{nullptr};
        };

        private:
        static thisPtr m_ptr;
        Data m_Data{};
        Size m_DataSize{};
    };
}; //namespace document