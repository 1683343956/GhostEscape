#include "scene_main.h"
#include "player.h"
#include "enemy.h"

void SceneMain::init()
{
    world_size_ = game_.getScreenSize() * 3.0f;
    camera_position_ = world_size_ / 2.0f - game_.getScreenSize() / 2.0f;
    player_ = new Player();
    player_->init();
    player_->setPosition(world_size_ / 2.0f);
    addChild(player_);

    auto enemy = new Enemy();
    enemy->init();
    enemy->setPosition(world_size_/2.0f+glm::vec2(200.0f));
    enemy->setTarget(player_);
    addChild(enemy);
}

void SceneMain::update(float deltaTime)
{
    Scene::update(deltaTime);
}

void SceneMain::render()
{
    renderBackground();
    Scene::render();
}

void SceneMain::handleEvents(SDL_Event &event)
{
    Scene::handleEvents(event);
    player_->handleEvents(event);
}

void SceneMain::clean()
{
    Scene::clean();
}

void SceneMain::renderBackground()
{
    auto start = -camera_position_;
    auto end = world_size_ - camera_position_;
    game_.drawGrid(start, end, 80, {0.5, 0.5, 0.5, 0.5});
    game_.drawBoundary(start, end, 5.0f, {1.0, 1.0, 1.0, 1.0});
}
