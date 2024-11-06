#pragma once
#include "I_Attributes.h"
#include "BoundingBox.h"
#include "ItemInfo.h"
#include <memory>
#include <utility>

namespace document {
    class A_Item {
        public:
        using Location = std::pair<float, float>;
        using AttributePtr = std::shared_ptr<I_Attributes>;
        using BoundingBoxPtr = std::shared_ptr<Bounding_Box>;
        using ItemPtr = std::unique_ptr<A_Item>;
        using ItemInfo = cli::ItemInfo;
        using ItemInfoPtr = std::shared_ptr<ItemInfo>;
        using ID = size_t;

        public:
        A_Item(A_Item&&) noexcept;
        A_Item& operator=(A_Item&&) noexcept;
        virtual ItemPtr create(ItemInfoPtr, const ID) = 0;
        virtual ~A_Item() = default;

        public:
        A_Item(const Location&, const AttributePtr);
        void move(const Location&);
        Location getGeometry() const;
        void setGeometry(const Location&);
        ID getId() const;

        public:
        bool friend operator==(const A_Item&, const A_Item&) noexcept;
        const BoundingBoxPtr getBoundingBox() const;
        const AttributePtr getAttributes() const;

        protected:
        BoundingBoxPtr m_BoundingBox{nullptr};
        AttributePtr m_Attributes{nullptr};
    };

} //namespace document