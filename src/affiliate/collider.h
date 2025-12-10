#pragma once
#include "../core/object_affiliate.h"

class Collider : public ObjectAffiliate
{
    enum class Type
    {
        CIRCLE, // size_的x轴为直径,默认y=x
        RECTANGLE,
    };
    Type type_ = Type::CIRCLE;

public:
    static Collider *addColliderChild(ObjectScreen *parent, glm::vec2 size,
                                      Type type = Type::CIRCLE, Anchor anchor = Anchor::CENTER);
    void render() override;

    bool isColliding(Collider *other);
    void setType(Type type) { type_ = type; }
    Type getType() { return type_; }
};