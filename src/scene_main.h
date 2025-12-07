#pragma once
#include "core/scene.h"

class Player;
class SceneMain : public Scene
{
private:
    Player *player_ = nullptr;

public:
    SceneMain() = default;
    virtual ~SceneMain() = default;
    void init();
    void update(float deltaTime);
    void render();
    void handleEvents(SDL_Event &event);
    void clean();

private:
    void renderBackground();
};