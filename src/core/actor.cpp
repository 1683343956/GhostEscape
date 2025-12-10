#include "actor.h"
#include "scene.h"
#include "../raw/stats.h"

void Actor::move(float deltaTime)
{
    setPosition(position_ + velocity_ * deltaTime);
    position_ = glm::clamp(position_, glm::vec2(0), game_.getCurrentScene()->getWorldSize());
}

void Actor::takeDamage(float damage)
{
    if (!stats_)
        return;
    stats_->takeDamage(damage);
}

bool Actor::isAlive()
{
    if (!stats_)
        return true;
    return stats_->isAlive();
}
