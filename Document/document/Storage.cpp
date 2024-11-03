#include "../../Include/Storage.h"

document::Storage::thisPtr document::Storage::m_ptr{nullptr};

document::Storage::thisPtr document::Storage::getInstance() {
    if (nullptr == m_ptr) {
        m_ptr.reset(new Storage());
    }
    return m_ptr;
}

document::Storage::iterator document::Storage::begin() {
    return iterator{0, m_Data};
}

bool document::Storage::isIndexValid(Index index) const {
    return (index >= 0 && index < m_DataSize) ? true : false;
}

document::Storage::iterator::iterator(size_t index, Data& m_data) {
    if (!isIndexValid(index, m_data.size())) {
        throw document::Invalid_Index("Index is not Valid", index);
    }
    setIterator(index, m_data);
}

document::Storage::iterator::iterator(IterPointer ptr) {
    m_Iterator = ptr;
}

bool document::Storage::iterator::isIndexValid(size_t index, size_t size) const {
    return (index == 0 || index == size);
}

void document::Storage::iterator::setIterator(size_t index, Data& m_data) {
    m_Iterator = (0 == index) ? std::make_shared<PointerType>(m_data.begin()) : std::make_shared<PointerType>(m_data.end());
}

document::Storage::iterator document::Storage::iterator::operator++() {
    iterator iter{m_Iterator};
    (*m_Iterator)++;
    return iter;
}

document::Storage::iterator& document::Storage::iterator::operator++(int) {
    ++(*m_Iterator);
    return *this;
}

document::Storage::iterator document::Storage::iterator::operator--() {
    iterator iter{m_Iterator};
    --(*m_Iterator);
    return iter;
}

document::Storage::iterator& document::Storage::iterator::operator--(int) {
    --(*m_Iterator);
    return *this;
}

document::Storage::iterator::ValueType document::Storage::iterator::operator*() {
    return *(*m_Iterator);
}

document::Storage::iterator& document::Storage::iterator::operator->() {
    return *this;
}


document::Storage::const_iterator::const_iterator(size_t index, const Data& m_data) {
    if (!isIndexValid(index, m_data.size())) {
        throw document::Invalid_Index("Index is not valid", index, std::source_location::current());
    }
    setIterator(index, m_data);
}

document::Storage::const_iterator::const_iterator(IterPointer ptr)
: m_iterator{ptr} {};

document::Storage::const_iterator document::Storage::const_iterator::operator++() {
    const_iterator iter{m_iterator};
    ++(*m_iterator);
    return iter;
}

document::Storage::const_iterator& document::Storage::const_iterator::operator++(int) {
    ++(*m_iterator);
    return *this;
}

document::Storage::const_iterator document::Storage::const_iterator::operator--() {
    const_iterator iter{m_iterator};
    --(*m_iterator);
    return iter;
}

document::Storage::const_iterator& document::Storage::const_iterator::operator--(int) {
    --(*m_iterator);
    return *this;
}

document::Storage::const_iterator::ValueType document::Storage::const_iterator::operator*() {
    return *(*m_iterator);
}

document::Storage::const_iterator& document::Storage::const_iterator::operator->() {
    return *this;
}

bool document::Storage::const_iterator::isIndexValid(size_t index, size_t size) const {
    return (index == 0 || index == size);
}

void document::Storage::const_iterator::setIterator(size_t index, const Data& m_data) {
    m_iterator = (0 == index) ? std::make_shared<PointerType>(m_data.cbegin()) : std::make_shared<PointerType>(m_data.cend());
}


