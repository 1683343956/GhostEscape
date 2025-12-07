#pragma once
#include "core/actor.h"

class Player : public Actor
{
public:
    virtual void init();
    virtual void handleEvents(SDL_Event &event);
    virtual void update(float deltaTime);
    virtual void render();
    virtual void clean();

    void keyboardControl();
    void move(float deltaTime);
    void syncCamera();

private:
    bool is_move_up_= false;
    bool is_move_down_= false;
    bool is_move_left_= false;
    bool is_move_right_= false;
};