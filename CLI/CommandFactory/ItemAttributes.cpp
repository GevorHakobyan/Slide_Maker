#include "ItemAttributes.h"

namespace cli{
    void ItemAttributes::addAttribute(const Key key, const Value& val) {
        _attributes[key] = val;
    }
    
    ItemAttributes::Color ItemAttributes::getColor() const {
        const auto iter = _attributes.find("color");
        return std::get<Color>((*iter).second);
    }

    ItemAttributes::Type ItemAttributes::getType() const {
        const auto iter = _attributes.find("type");
        return std::get<Type>((*iter).second);
    }
    
    ItemAttributes::Title ItemAttributes::getTitle() const {
        const auto iter = _attributes.find("title");
        return std::get<Title>((*iter).second);
    }

    ItemAttributes::Content ItemAttributes::getContent() const {
        const auto iter = _attributes.find("content");
        return std::get<Content>((*iter).second);
    }

    ItemAttributes::Radius ItemAttributes::getRadius() const {
        const auto iter = _attributes.find("radius");
        return std::get<Radius>((*iter).second);
    }

    ItemAttributes::Vertexes ItemAttributes::getVertexes() const {
        const auto iter = _attributes.find("vertexes");
        return std::get<Vertexes>((*iter).second);
    }

    ItemAttributes::Center ItemAttributes::getCenter() const {
        const auto iter = _attributes.find("center");
        return std::get<Center>((*iter).second);
    }

    ItemAttributes::Length ItemAttributes::getLength() const {
        const auto iter = _attributes.find("length");
        return std::get<Length>((*iter).second);
    }

    ItemAttributes::Width ItemAttributes::getWidth() const {
        const auto iter  = _attributes.find("width");
        return std::get<Width>((*iter).second);
    }

    ItemAttributes::Location ItemAttributes::getLocation() const {
        const auto iter = _attributes.find("location");
        return std::get<Location>((*iter).second);
    }

}; //namespace cli