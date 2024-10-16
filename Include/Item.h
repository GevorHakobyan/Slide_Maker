#pragma once
#include "I_Attributes.h"
#include <memory>
#include <utility>

namespace document {

    class A_Item {
        public:
        using Location = std::pair<float, float>;
        using AttributePtr = std::shared_ptr<I_Attributes>;

        public:
        A_Item() = default;
        A_Item(const Location&, AttributePtr);
        A_Item(A_Item&&) noexcept;
        A_Item& operator=(A_Item&&) noexcept;
        virtual ~A_Item() = default;
        virtual void setGeometry(const Location&) = 0;
        virtual void setAttributes(const I_Attributes&) = 0;

        public:
        bool friend operator==(const A_Item&, const A_Item&) noexcept;
        Location&& getGeometry();
        AttributePtr getAttributesPtr();

        protected:
        Location m_geometry;
        AttributePtr m_attributesPtr{nullptr};

    };

} //namespace document