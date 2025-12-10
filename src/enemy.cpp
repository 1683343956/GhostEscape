#include "enemy.h"
#include "core/scene.h"
#include "raw/stats.h"

void Enemy::init()
{
    Actor::init();
    anim_normal_ = SpriteAnim ::addSpriteAnimChild(this, "assets/sprite/ghost-Sheet.png", 2.0f);
    anim_hurt_ = SpriteAnim ::addSpriteAnimChild(this, "assets/sprite/ghostHurt-Sheet.png", 2.0f);
    anim_die_ = SpriteAnim ::addSpriteAnimChild(this, "assets/sprite/ghostDead-Sheet.png", 2.0f);
    anim_hurt_->setActive(false);
    anim_die_->setActive(false);
    anim_die_->setLoop(false);

    current_anim_ = anim_normal_;
    collider_ = Collider::addColliderChild(this, current_anim_->getSize());
    stats_=Stats::addStatsChild(this);
}

void Enemy::update(float delta)
{
    Actor::update(delta);
    aim_target(target_);
    move(delta);
    attack();
}

void Enemy::aim_target(Player *target)
{
    if (target_ == nullptr)
        return;
    auto dirction = target->getPosition() - this->getPosition();
    dirction = glm::normalize(dirction);
    velocity_ = dirction * max_speed_;
}

void Enemy::checkState()
{
}

void Enemy::changeState(State newState)
{
    if (currentState_ == newState)
        return;
    current_anim_->setActive(false);
    switch (newState)
    {
    case State::NORMAL:
        current_anim_ = anim_normal_;
        break;
    case State::HURT:
        current_anim_ = anim_hurt_;
        break;
    case State::DIE:
        current_anim_ = anim_die_;
        break;
    default:
        break;
    }
    current_anim_->setActive(true);
    currentState_ = newState;
}

void Enemy::attack()
{
    if(!collider_||!target_->getCollider())
        return;
     if(collider_->isColliding(target_->getCollider()))   
     {
        if(stats_&&target_->getStats())
        {
            target_->takeDamage(stats_->getDamage());
        }
     }
}

void Enemy::remove()
{
    if(anim_die_->getFinish())
    {
        need_remove_ = true;
        // game_.getCurrentScene()->removeChild(this);
        // clean();
        // delete this;
    }
}
