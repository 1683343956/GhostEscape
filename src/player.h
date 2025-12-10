#pragma once
#include "core/actor.h"
#include "affiliate/sprite_anim.h"

class Player : public Actor
{
public:
    virtual void init();
    virtual void handleEvents(SDL_Event &event);
    virtual void update(float deltaTime);
    virtual void render();
    virtual void clean();

    void keyboardControl();
    virtual void move(float deltaTime) override;
    void syncCamera();
    void checkStates();
    void changeState(bool is_moving);

private:
    bool is_move_up_ = false;
    bool is_move_down_ = false;
    bool is_move_left_ = false;
    bool is_move_right_ = false;

    SpriteAnim *sprite_idle_ = nullptr;
    SpriteAnim *sprite_move_ = nullptr;
    bool is_moving_ = false;
};