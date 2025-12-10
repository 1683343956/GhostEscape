#pragma once
#include "player.h"
#include "affiliate/sprite_anim.h"

class Enemy : public Actor
{
private:
    enum class State
    {
        NORMAL,
        HURT,
        DIE
    };
    State currentState_ = State::NORMAL;
    Player *target_ = nullptr;
    SpriteAnim *anim_normal_ = nullptr;
    SpriteAnim *anim_hurt_ = nullptr;
    SpriteAnim *anim_die_ = nullptr;
    SpriteAnim *current_anim_ = nullptr;

public:
    virtual void init() override;
    virtual void update(float delta) override;

    void aim_target(Player *target);

    void checkState();
    void changeState(State newState);
    void attack();

    Player *getTarget() { return target_; }
    void setTarget(Player *target) { target_ = target; }
    void remove() ;
};