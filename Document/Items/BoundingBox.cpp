#include "BoundingBox.h"
document::Bounding_Box::thisPtr document::Bounding_Box::CR_BoundingBox(const AttributePtr atr) {
    const auto radius = atr->getRadius();
    const auto center = atr->getCenter();
    thisPtr box = std::make_unique<Bounding_Box>();

    box->setOrigin(center);
    box->setLength(2 * radius);
    box->setWidth(2 * radius);
    return std::move(box);
}

document::Bounding_Box::thisPtr document::Bounding_Box::TR_BoundingBox(const AttributePtr atr) {
    const auto[Br, Bl, T] = atr->getVertexes();
    thisPtr box = std::make_unique<Bounding_Box>();

    box->setOrigin(Br);
    box->setLength(std::abs(Br.second - Bl.second));
    box->setWidth(std::abs(T.first - Br.first));
    return std::move(box);
}

document::Bounding_Box::thisPtr document::Bounding_Box::RC_BoundingBox(const AttributePtr atr) {
    const auto origin = atr->getLocation();
    const auto length = atr->getLength();
    const auto width = atr->getWidth();
    thisPtr box = std::make_unique<Bounding_Box>();

    box->setOrigin(origin);
    box->setLength(length);
    box->setWidth(width);
    return std::move(box);
}

void document::Bounding_Box::setOrigin(Pair origin) {
    m_Origin = origin;
}

void document::Bounding_Box::setLength(float length) {
    m_Length = length;
}

void document::Bounding_Box::setWidth(float width) {
    m_Width = width;
}

float document::Bounding_Box::getLength() const {
    return m_Length;
}

float document::Bounding_Box::getWidth() const {
    return m_Width;
}

document::Bounding_Box::Pair document::Bounding_Box::getCurrentPostion() const {
    return m_CurrentPosition;
}

void document::Bounding_Box::moveObject(Pair newLocation) {
    setCurrentPostion(newLocation);
} 

void document::Bounding_Box::setCurrentPostion(Pair newLocation) {
    const auto[Ny , Nx] = newLocation;
    const auto[Oy, Ox] = m_Origin;

    m_CurrentPosition.first = (Ny - Oy);
    m_CurrentPosition.second = (Nx - Ox);
}
