#include "Storage.h"

document::Storage::thisPtr document::Storage::m_ptr{nullptr};

document::Storage::iterator document::Storage::begin() {
    return iterator{0, m_Data};
}

document::Storage::iterator document::Storage::end() {

    return iterator{m_DataSize, m_Data};
}

document::Storage::const_iterator document::Storage::cbegin() const {
    return const_iterator{0, m_Data};
}

document::Storage::const_iterator document::Storage::cend() const {
    return const_iterator{m_DataSize, m_Data};
}

void document::Storage::insert(SlideUptr slide, Position pos) {
    m_Data.insert(m_Data.cbegin() + pos, std::move(slide));
    ++m_DataSize;
}

bool document::Storage::isIndexValid(Index index) const {
    return (index >= 0 && index < m_DataSize) ? true : false;
}

void document::Storage::erase(const Position position) {
    auto iter = m_Data.begin() + position;
    m_Data.erase(iter);
}

document::Storage::Size document::Storage::getSize() const {
    return m_DataSize;
}

document::Storage::iterator::iterator(size_t index, Data& m_data) {
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

document::Storage::iterator::PointerType document::Storage::iterator::operator->() {
    return *m_Iterator;
}

const document::Storage::iterator::ValueType document::Storage::iterator::operator*() const {
    return *(*m_Iterator);
}

const document::Storage::iterator::PointerType document::Storage::iterator::operator->() const {
    return *m_Iterator;
}

namespace document{
    bool operator==(const Storage::iterator& rhs, const Storage::iterator& lfs) {
        return *rhs.m_Iterator == *lfs.m_Iterator;
    }


    bool operator!=(const Storage::iterator& rhs, const Storage::iterator& lfs) {
        return *rhs.m_Iterator != *lfs.m_Iterator;
    }

}

document::Storage::const_iterator::const_iterator(size_t index, const Data& m_data) {
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

document::Storage::const_iterator::PointerType document::Storage::const_iterator::operator->() {
    return *m_iterator;
}

const document::Storage::const_iterator::ValueType document::Storage::const_iterator::operator*() const {
    return *(*m_iterator);
}

const document::Storage::const_iterator::PointerType document::Storage::const_iterator::operator->() const {
    return *m_iterator;
}
namespace document {

    bool operator==(const Storage::const_iterator& rhs, const Storage::const_iterator& lfs) {
        return rhs.m_iterator == lfs.m_iterator;
    }

    bool operator!=(const Storage::const_iterator& rhs, const Storage::const_iterator& lfs) {
        return rhs.m_iterator != lfs.m_iterator;
    }

}

bool document::Storage::const_iterator::isIndexValid(size_t index, size_t size) const {
    return (index == 0 || index == size);
}

void document::Storage::const_iterator::setIterator(size_t index, const Data& m_data) {
    m_iterator = (0 == index) ? std::make_shared<PointerType>(m_data.cbegin()) : std::make_shared<PointerType>(m_data.cend());
}


