#include "IAttributes.h"

namespace cli
{
    struct ItemAttributes : public document::IAttributes {
        void addAttribute(const Key, const Value&) override;
        Color getColor() const override;
        Title getTitle() const override;
        Type getType() const override;
        Content getContent() const override;
        Radius getRadius() const override;
        Vertexes getVertexes() const override;
        Center getCenter() const override;
        Width getWidth() const override;
        Length getLength() const override;
        Location getLocation() const override;
    };
} // namespace cli
