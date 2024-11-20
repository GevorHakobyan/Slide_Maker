#include "BoundingBox.h"

void document::Bounding_Box::setLength(Length length) {
    m_Length = length;
}

void document::Bounding_Box::setWidth(Width width) {
    m_Width = width;
}

void document::Bounding_Box::setOrigin(Origin origin) {
    m_Origin = origin;
}

document::Bounding_Box::Length document::Bounding_Box::getLength() const {
    return m_Length;
}

document::Bounding_Box::Width document::Bounding_Box::getWidth() const {
    return m_Width;
}

document::Bounding_Box::Location document::Bounding_Box::getCurrentPostion() const {
    return m_CurrentPosition;
}

void document::Bounding_Box::moveObject(Location newLocation) {
    setCurrentPostion(newLocation);
} 

void document::Bounding_Box::setCurrentPostion(Location newLocation) {
    const auto[Ny , Nx] = newLocation;
    const auto[Oy, Ox] = m_Origin;

    m_CurrentPosition.first = (Ny - Oy);
    m_CurrentPosition.second = (Nx - Ox);
}
