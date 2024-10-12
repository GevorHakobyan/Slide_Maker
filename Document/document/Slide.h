#pragma once
#include <vector>
#include "InvalidIndex_Cerr.h"

namespace document {

    class Slide {
       public:
       using Data = std::vector<int>;
       using Iterator = Data::iterator;
       using ConstIterator = Data::const_iterator;
       using Index = size_t;
       using Size = size_t;

       public:
       Slide(Size);
       ~Slide() = default;
       Slide(Slide&&) noexcept;
       Slide& operator=(Slide&&) noexcept;
       Slide(const Slide&) noexcept;
       Slide& operator=(const Slide&) noexcept;
       friend bool operator==(const Slide&, const Slide&);
       friend void Swap(Slide&, Slide&) noexcept;

       Size getItemCount() const;
       ConstIterator getIteratorOn(Index) const;
       Iterator getIteratorOn(Index);
       private:
       void assignInfo(const Slide&);
       bool isIndexValid(Index) const;
       
       private:
       Data m_data{};
       Size m_dataSize{};
    };
} // namespace document

