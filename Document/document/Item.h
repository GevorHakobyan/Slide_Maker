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

        public:
        A_Item(A_Item&&) noexcept;
        A_Item& operator=(A_Item&&) noexcept;
        virtual ~A_Item() = default;
        virtual A_Item create(const Location, const AttributePtr) = 0;

        protected:
        A_Item() = default;
        A_Item(const Location&, AttributePtr);
        void move(const Location&);
        virtual void setGeometry(const Location&) = 0;
        virtual void setAttributes(const I_Attributes&) = 0;

        public:
        bool friend operator==(const A_Item&, const A_Item&) noexcept;
        Location&& getGeometry();
        AttributePtr getAttributesPtr();

        protected:
        BoundingBoxPtr m_BoundingBox{nullptr};
        Location m_geometry;
        AttributePtr m_attributesPtr{nullptr};

    };

} //namespace document