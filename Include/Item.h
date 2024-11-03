#pragma once
#include "I_Attributes.h"
#include "BoundingBox.h"
#include <memory>
#include <utility>

namespace document {

    class A_Item {
        public:
        using Location = std::pair<float, float>;
        using AttributePtr = std::shared_ptr<I_Attributes>;
        using BoundingBoxPtr = std::shared_ptr<Bounding_Box>;
        using ItemPtr = std::unique_ptr<A_Item>;
        using ID = size_t;

        public:
        A_Item(A_Item&&) noexcept;
        A_Item& operator=(A_Item&&) noexcept;
        virtual ItemPtr create(const Location, const AttributePtr) = 0;
        virtual ~A_Item() = default;

        protected:
        A_Item(const Location&, const AttributePtr, const ID);
        void move(const Location&);
        void setGeometry(const Location&);
        void setAttributes(const AttributePtr);

        public:
        bool friend operator==(const A_Item&, const A_Item&) noexcept;
        Location getGeometry();
        AttributePtr getAttributesPtr();
        BoundingBoxPtr getBoundingBox();
        ID getId() const;

        protected:
        BoundingBoxPtr m_BoundingBox{nullptr};
        AttributePtr m_attributesPtr{nullptr};
        const ID m_id;
    };

} //namespace document