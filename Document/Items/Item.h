#pragma once
#include "Attributes.h"
#include "BoundingBox.h"
#include <memory>
#include <map>
#include <functional>

namespace document {
    class Item {
        public:
        using Location = std::pair<float, float>;
        using AttributePtr = std::shared_ptr<Attributes>;
        using BoundingBoxPtr = std::shared_ptr<Bounding_Box>;
        using U_BoundingBox = std::unique_ptr<Bounding_Box>;
        using ItemPtr = std::unique_ptr<Item>;
        using Map = std::map<std::string, std::function<U_BoundingBox(AttributePtr)>>;
        using ID = size_t;

        public:
        Item() = default;
        Item(Item&&) noexcept;
        Item& operator=(Item&&) noexcept;
        static ItemPtr create(AttributePtr);
        void setBoundingBox();

        public:
        Item(AttributePtr);
        void move(const Location&);
        const AttributePtr getAttributes() const;
        const BoundingBoxPtr getBoundingBox() const;
        ID getId() const;

        public:
        bool friend operator==(const Item&, const Item&) noexcept;

        private:
        static Map m_BoundingBox_Creators;
        BoundingBoxPtr m_BoundingBox{nullptr};
        AttributePtr m_Attributes{nullptr};
    };

} //namespace document