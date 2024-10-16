#include "Storage.h"

document::Storage::thisPtr document::Storage::m_ptr{nullptr};

document::Storage::thisPtr document::Storage::getInstance() {
    if (nullptr == m_ptr) {
        m_ptr.reset(new Storage());
    }
    return m_ptr;
}

document::Storage::Iterator document::Storage::getIteratorOn(Index index) {
    if (!isIndexValid(index)) {
        throw Invalid_Index("Invalid index", index, std::source_location::current());
    }

    return m_Data.begin() + index;
}

document::Storage::ConstIterator document::Storage::getIteratorOn(Index index) const {
    if (!isIndexValid(index)) {
        throw Invalid_Index("Invalid index", index, std::source_location::current());
    }

    return m_Data.cbegin() + index;
}

bool document::Storage::isIndexValid(Index index) const {
    return (index >= 0 && index < m_DataSize) ? true : false;
}