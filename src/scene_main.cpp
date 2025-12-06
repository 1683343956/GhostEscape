#include "scene_main.h"

void SceneMain::init()
{
    world_size_=game_.getScreenSize()*3.0f;
    camera_position = glm::vec2(-100,-100);
}

void SceneMain::update(float deltaTime)
{
    camera_position += deltaTime*glm::vec2(10,10);
}

void SceneMain::render()
{
    renderBackground();
}

void SceneMain::handleEvents(SDL_Event &event)
{
}

void SceneMain::clean()
{
}

void SceneMain::renderBackground()
{
    auto start = -camera_position;
    auto end = world_size_ - camera_position;
    game_.drawGrid(start, end,80, {0.5,0.5,0.5,0.5});
    game_.drawBoundary(start, end,5.0f, {1.0,1.0,1.0,1.0});
}
