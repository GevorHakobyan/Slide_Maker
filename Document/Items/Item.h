#pragma once
#include "Attributes.h"
#include "BoundingBox.h"
#include <memory>
#include <utility>

namespace document {
    class A_Item {
        public:
        using Location = std::pair<float, float>;
        using AttributePtr = std::shared_ptr<Attributes>;
        using BoundingBoxPtr = std::shared_ptr<Bounding_Box>;
        using ItemPtr = std::unique_ptr<A_Item>;
        using ID = size_t;

        public:
        A_Item(A_Item&&) noexcept;
        A_Item& operator=(A_Item&&) noexcept;
        virtual ItemPtr create(AttributePtr) = 0;
        virtual ~A_Item() = default;

        public:
        A_Item(AttributePtr);
        void move(const Location&);
        const AttributePtr getAttributes() const;
        const BoundingBoxPtr getBoundingBox() const;
        Location getGeometry() const;
        void setGeometry(const Location&);
        ID getId() const;

        public:
        bool friend operator==(const A_Item&, const A_Item&) noexcept;

        protected:
        BoundingBoxPtr m_BoundingBox{nullptr};
        AttributePtr m_Attributes{nullptr};
    };

} //namespace document