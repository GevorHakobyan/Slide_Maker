#pragma once
#include "Slide.h"
#include "InvalidIndex_Cerr.h"
#include <vector>
#include <memory>

namespace document {
    class Storage {
        public:
        using Data = std::vector<document::Slide>;
        using thisPtr = std::shared_ptr<Storage>;
        using Iterator = Data::iterator;
        using ConstIterator = Data::const_iterator;
        using Index = size_t;
        using Size = size_t;

        public:
        ~Storage() = default;
        thisPtr getInstance();
        Iterator getIteratorOn(Index);
        ConstIterator getIteratorOn(Index) const;

        private:
        bool isIndexValid(Index) const;
        private:
        static thisPtr m_ptr;
        Data m_Data{};
        Size m_DataSize{};
    };
}; //namespace document