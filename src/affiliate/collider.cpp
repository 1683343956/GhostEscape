#include "collider.h"

Collider *Collider::addColliderChild(ObjectScreen *parent, glm::vec2 size, Type type, Anchor anchor)
{
    auto collider = new Collider();
    collider->init();
    collider->setParent(parent);
    collider->setType(type);
    collider->setSize(size);
    collider->setOffsetByAnchor(anchor);
    // collider->parent_ = parent;
    // collider->type_ = type;
    // collider->size_ = size;
    // collider->anchor_ = anchor;
    parent->addChild(collider);
    return collider;
}

void Collider::render()
{
#ifdef DEBUG_MODE
    ObjectAffiliate::render();
    auto pos = parent_->getRenderPosition() + offset_;
    game_.renderFillCircle(pos, size_, 0.3f);
#endif
}

bool Collider::isColliding(Collider *other)
{
    if (!other)
        return false;
    if (type_ == Type::CIRCLE && other->type_ == Type::CIRCLE) // 两个圆的碰撞检测
    {
        auto point1 = parent_->getPosition() + offset_ + size_ / 2.0f;
        auto point2 = other->parent_->getPosition() + other->offset_ + other->size_ / 2.0f;
        return glm::length(point1 - point2) < (size_.x + other->size_.x) / 2.0f;
    }
    // 其他情况暂时不处理

    return false;
}
