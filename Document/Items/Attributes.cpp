#include "Attributes.h"

namespace document{

    Attributes::Attributes(Map map)
    : _attributes{std::move(map)} {};

    void Attributes::addAttribute(const Key key, const Value& val) {
            _attributes[key] = val;
        }
        
    cli::Color Attributes::getColor() const {
            const auto iter = _attributes.find("cr");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute color dosn't exist", std::source_location::current());
            }

            return std::get<Color>((*iter).second);
        }

        document::Attributes::Type Attributes::getType() const {
            const auto iter = _attributes.find("t");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Type dosn't exist", std::source_location::current());
            }

            return std::get<Type>((*iter).second);
        }
        
        Attributes::String Attributes::getTitle() const {
            const auto iter = _attributes.find("tit");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Title dosn't exist", std::source_location::current());
            }

            return std::get<String>((*iter).second);
        }

        Attributes::String Attributes::getContent() const {
            const auto iter = _attributes.find("ct");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Content dosn't exist", std::source_location::current());
            }

            return std::get<String>((*iter).second);
        }

        float Attributes::getRadius() const {
            const auto iter = _attributes.find("rd");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Radius dosn't exist", std::source_location::current());
            }
            return std::get<float>((*iter).second);
        }

        Attributes::Tuple Attributes::getVertexes() const {
            const auto iter = _attributes.find("vt");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Vertexes dosn't exist", std::source_location::current());
            }

            return std::get<Tuple>((*iter).second);
        }

        Attributes::Pair Attributes::getCenter() const {
            const auto iter = _attributes.find("cn");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Center dosn't exist", std::source_location::current());
            }
            return std::get<Pair>((*iter).second);
        }

        Attributes::Location Attributes::getLocation() {
            const auto iter = _attributes.find("lc");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Location dosn't exist", std::source_location::current());
            }

            auto location = std::get<Location>((*iter).second);
            _attributes.extract(iter);
            return location;
        }

        Attributes::Length Attributes::getLength() {
            const auto iter = _attributes.find("ln");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Length dosn't exist", std::source_location::current());
            }

            auto length = std::get<Length>((*iter).second);
            _attributes.extract(iter);
            return length;
        }

        Attributes::Width Attributes::getWidth() {
            const auto iter = _attributes.find("wd");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute width dosn't exist", std::source_location::current());
            }

            auto width = std::get<Width>((*iter).second);
            _attributes.extract(iter);
            return width;
        }

        Attributes::ID Attributes::getOwnerId() const {
            const auto iter = _attributes.find("oid");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute Owner Id dosn't exist", std::source_location::current());
            }

            return std::get<ID>((*iter).second);
        }

        Attributes::ID Attributes::getId() const {
            const auto iter = _attributes.find("id");
            if (iter == _attributes.end()) {
                throw InvalidAccess("Attribute ID dosn't exist", std::source_location::current());
            }
            return std::get<ID>((*iter).second);
        }
}; //namespace cli