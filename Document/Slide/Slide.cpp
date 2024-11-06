#include "Slide.h"

document::Slide::Slide(Data&& itemList, const ID id)
: m_dataSize{itemList.size()}, m_data{}, m_id{id} {
    for (auto& ptr : itemList) {
        m_data.push_back(ptr);
    }
}

document::Slide::Slide(Slide&& rhs) noexcept {
    Swap(*this, rhs);
}

document::Slide& document::Slide::operator=(Slide&& rhs) noexcept {
    Swap(*this, rhs);
    return *this;
}

document::Slide::Slide(const Slide& rhs) noexcept 
: m_data(rhs.getItemCount()), m_dataSize{rhs.getItemCount()} {
    this->assignInfo(rhs);
}

document::Slide& document::Slide::operator=(const Slide& rhs) noexcept {
    if (*this == rhs) {
        return *this;
    }

    Slide tmp{rhs};
    this->operator=(std::move(tmp));
    return *this;
}

void document::Swap(Slide& first, Slide& second) noexcept {
    std::swap(first.m_data, second.m_data);
    std::swap(first.m_dataSize, second.m_dataSize);
}

void document::Slide::erase(ItemPtr ptr) {
    auto it  = std::ranges::find(m_data, ptr);
    m_data.erase(it);
}

document::Slide::Iterator document::Slide::begin() {
    return Iterator(0, m_data);
}

document::Slide::Iterator document::Slide::end() {
    return Iterator(m_data.size(), m_data);
}

document::Slide::ConstIterator document::Slide::cbegin() const {
    return ConstIterator(0, m_data);
}

document::Slide::ConstIterator document::Slide::cend() const {
    return ConstIterator(m_data.size(), m_data);
}

document::Slide::Size document::Slide::getItemCount() const {
    return m_dataSize;
}

document::Slide::ID document::Slide::getId() const {
    return m_id;
}

bool document::operator==(const Slide& first, const Slide& second) {
    return (&first.m_data == &second.m_data);
}

void document::Slide::assignInfo(const Slide& rhs) {
    const auto dataSize{rhs.getItemCount()};
    auto iter = rhs.cbegin();

    for (size_t i{0}; i < dataSize; ++i) {
        m_data[i] = *iter;
        ++iter;
    }
}

bool document::Slide::isIndexValid(Index index) const {
    return (index >= 0 && index < m_dataSize) ? true : false;
}

document::Slide::Iterator::Iterator(size_t index, Data& m_data) {
    if (!isIndexValid(index, m_data.size())) {
        throw document::Invalid_Index("Index is not Valid", index);
    }
    setIterator(index, m_data);
}

document::Slide::Iterator::Iterator(IterPointer ptr) {
    m_iterator = ptr;
}

bool document::Slide::Iterator::isIndexValid(size_t index, size_t size) const {
    return (index == 0 || index == size);
}

void document::Slide::Iterator::setIterator(size_t index, Data& m_data) {
    m_iterator = (0 == index) ? std::make_shared<PointerType>(m_data.begin()) : std::make_shared<PointerType>(m_data.end());
}

document::Slide::Iterator document::Slide::Iterator::operator++() {
    Iterator iter{m_iterator};
    (*m_iterator)++;
    return iter;
}

document::Slide::Iterator& document::Slide::Iterator::operator++(int) {
    ++(*m_iterator);
    return *this;
}

document::Slide::Iterator::ValueType document::Slide::Iterator::operator*() {
    return *(*m_iterator);
}

document::Slide::Iterator::IterPointer document::Slide::Iterator::operator->() {
    return m_iterator;
}

const document::Slide::Iterator::ValueType document::Slide::Iterator::operator*() const {
    return *(*m_iterator);
}

const document::Slide::Iterator::IterPointer document::Slide::Iterator::operator->() const {
    return m_iterator;
}

bool document::Slide::Iterator::operator==(const Iterator& rhs) {
    return (*(*this))->getId() == (*rhs)->getId();
}

bool document::Slide::Iterator::operator!=(const Iterator& rhs) {
    return !(this->operator==(rhs));
}

document::Slide::ConstIterator::ConstIterator(size_t index, const Data& m_data) {
    if (!isIndexValid(index, m_data.size())) {
        throw document::Invalid_Index("Index is not valid", index, std::source_location::current());
    }
    setIterator(index, m_data);
}

document::Slide::ConstIterator::ConstIterator(IterPointer ptr)
: m_iterator{ptr} {};

document::Slide::ConstIterator document::Slide::ConstIterator::operator++() {
    ConstIterator iter{m_iterator};
    ++(*m_iterator);
    return iter;
}

document::Slide::ConstIterator& document::Slide::ConstIterator::operator++(int) {
    ++(*m_iterator);
    return *this;
}

document::Slide::ConstIterator::ValueType document::Slide::ConstIterator::operator*() {
    return *(*m_iterator);
}

document::Slide::ConstIterator::IterPointer document::Slide::ConstIterator::operator->() {
    return m_iterator;
}

const document::Slide::ConstIterator::ValueType document::Slide::ConstIterator::operator*() const {
    return *(*m_iterator);
}

const document::Slide::ConstIterator::IterPointer document::Slide::ConstIterator::operator->() const {
    return m_iterator;
}

bool document::Slide::ConstIterator::operator==(const ConstIterator& rhs) {
    return (*(*this->m_iterator))->getId() == (*(*rhs.m_iterator))->getId();
}

bool document::Slide::ConstIterator::operator!=(const ConstIterator& rhs) {
    return !(this->operator==(rhs));
}

bool document::Slide::ConstIterator::isIndexValid(size_t index, size_t size) const {
    return (index == 0 || index == size);
}

void document::Slide::ConstIterator::setIterator(size_t index, const Data& m_data) {
    m_iterator = (0 == index) ? std::make_shared<PointerType>(m_data.cbegin()) : std::make_shared<PointerType>(m_data.cend());
}


