#pragma once
#include "game.h"

class Object
{
protected:
    Game &game_ = Game::GetInstance();

public:
    Object() = default;
    virtual ~Object() = default;
    virtual void init() {};
    virtual void handleEvents(SDL_Event &event) {};
    virtual void update(float deltaTime) {};
    virtual void render() {};
    virtual void clean() {};
};