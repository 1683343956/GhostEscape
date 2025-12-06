#pragma once
#include"core/scene.h"

class SceneMain : public Scene
{
private:
    glm::vec2 world_size_= glm::vec2(0);
public:
    SceneMain()=default;
    virtual ~SceneMain()=default;
    void init() ;
    void update(float deltaTime) ;
    void render() ;
    void handleEvents(SDL_Event &event) ;
    void clean() ;
private:
    void renderBackground();

};