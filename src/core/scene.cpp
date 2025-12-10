#include "scene.h"

void Scene::init()
{
}
void Scene::update(float deltaTime)
{
    Object::update(deltaTime);

    for (auto it = children_screen_.begin(); it != children_screen_.end();)
    {
        auto child = *it;
        if (child->getNeedRemove())
        {
            it = children_screen_.erase(it);
            child->clean();
            delete child;
        }
        else
        {
            if (child->getActive())
            {
                child->update(deltaTime);
            }
            ++it;
        }
    }

    for (auto it = children_world_.begin(); it != children_world_.end();)
    {
        auto child = *it;
        if (child->getNeedRemove())
        {
            it = children_world_.erase(it);
            child->clean();
            delete child;
        }
        else
        {
            if (child->getActive())
            {
                child->update(deltaTime);
            }
            ++it;
        }
    }

    // for (auto &child : children_screen_)
    // {
    //     if (child->getActive())
    //     {
    //         child->update(deltaTime);
    //     }
    // }

    // for (auto &child : children_world_)
    // {
    //     if (child->getActive())
    //     {
    //         child->update(deltaTime);
    //     }
    // }
}
void Scene::render()
{
    Object::render();
    for (auto &child : children_world_)
    {
        if (child->getActive())
        {
            child->render();
        }
    }

    for (auto &child : children_screen_)
    {
        if (child->getActive())
        {
            child->render();
        }
    }
}
void Scene::handleEvents(SDL_Event &event)
{
    Object::handleEvents(event);
    for (auto &child : children_screen_)
    {
        if (child->getActive())
        {
            child->handleEvents(event);
        }
    }

    for (auto &child : children_world_)
    {
        if (child->getActive())
        {
            child->handleEvents(event);
        }
    }
}
void Scene::clean()
{
    Object::clean();
    for (auto &child : children_screen_)
    {
        child->clean();
    }

    for (auto &child : children_world_)
    {
        child->clean();
    }
}

void Scene::addChild(Object *child)
{
    switch (child->getType())
    {
    case ObjectType::OBJECT_WORLD:
        children_world_.push_back(dynamic_cast<ObjectWorld *>(child));
        break;
    case ObjectType::OBJECT_SCREEN:
        children_screen_.push_back(dynamic_cast<ObjectScreen *>(child));
        break;
    default:
        children_.push_back(child);
        break;
    }
}

void Scene::removeChild(Object *child)
{
    switch (child->getType())
    {
    case ObjectType::OBJECT_WORLD:
        children_world_.erase(
            std::remove(children_world_.begin(), children_world_.end(), child), children_world_.end());
        break;
    case ObjectType::OBJECT_SCREEN:
        children_screen_.erase(
            std::remove(children_screen_.begin(), children_screen_.end(), child), children_screen_.end());
        break;
    default:
        children_.erase(std::remove(children_.begin(), children_.end(), child), children_.end());
        break;
    }
}

void Scene::setCameraPosition(const glm::vec2 &camera_position)
{
    camera_position_ = camera_position;
    camera_position_ = glm::clamp(camera_position_, glm::vec2(-30.0f),
                                  world_size_ - game_.getScreenSize() + glm::vec2(30.0f));
}
