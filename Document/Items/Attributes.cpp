#include "Attributes.h"

namespace document{

   void Attributes::addAttribute(const Key key, const Value& val) {
        _attributes[key] = val;
    }
    
   cli::Color Attributes::getColor() const {
        const auto iter = _attributes.find("cr");
        return std::get<Color>((*iter).second);
    }

    cli::Type Attributes::getType() const {
        const auto iter = _attributes.find("t");
        return std::get<Type>((*iter).second);
    }
    
    Attributes::Title Attributes::getTitle() const {
        const auto iter = _attributes.find("tit");
        return std::get<Title>((*iter).second);
    }

    Attributes::Content Attributes::getContent() const {
        const auto iter = _attributes.find("ct");
        return std::get<Content>((*iter).second);
    }

    Attributes::Radius Attributes::getRadius() const {
        const auto iter = _attributes.find("r");
        return std::get<Radius>((*iter).second);
    }

    Attributes::Vertexes Attributes::getVertexes() const {
        const auto iter = _attributes.find("vt");
        return std::get<Vertexes>((*iter).second);
    }

    Attributes::Center Attributes::getCenter() const {
        const auto iter = _attributes.find("c");
        return std::get<Center>((*iter).second);
    }

    Attributes::Location Attributes::getLocation() const {
        const auto iter = _attributes.find("ln");
        return std::get<Location>((*iter).second);
    }

    Attributes::ID Attributes::getOwnerId() const {
        const auto iter = _attributes.find("oid");
        return std::get<ID>((*iter).second);
    }

    Attributes::ID Attributes::getId() const {
        const auto iter = _attributes.find("id");
        return std::get<ID>((*iter).second);
    }
}; //namespace cli