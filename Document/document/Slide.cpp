#include "Slide.h"

document::Slide::Slide(Size itemCount)
: m_data(itemCount), m_dataSize{itemCount} {};

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

document::Slide::Size document::Slide::getItemCount() const {
    return m_dataSize;
}

document::Slide::ConstIterator document::Slide::getIteratorOn(Index index) const {
    if (!isIndexValid(index)) {
        throw Invalid_Index("Invalid index", index, std::source_location::current());
    }
    return m_data.cbegin() + index;
}

document::Slide::Iterator document::Slide::getIteratorOn(Index index) {
    if (!isIndexValid(index)) {
        throw Invalid_Index("Invalid index", index, std::source_location::current());
    }
    return m_data.begin() + index;
}

bool document::operator==(const Slide& first, const Slide& second) {
    return (&first.m_data == &second.m_data);
}

void document::Slide::assignInfo(const Slide& rhs) {
    const auto dataSize{rhs.getItemCount()};

    for (size_t i{0}; i < dataSize; ++i) {
        m_data[i] = *rhs.getIteratorOn(i);
    }
}

bool document::Slide::isIndexValid(Index index) const {
    return (index >= 0 && index < m_dataSize) ? true : false;
}
