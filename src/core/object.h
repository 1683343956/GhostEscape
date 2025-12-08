#pragma once
#include "game.h"
#include "defs.h"

class Object
{
protected:
    ObjectType type_ = ObjectType::NONE;
    Game &game_ = Game::GetInstance();
    std::vector<Object *> children_;
    bool is_active_ = true;

public:
    Object() = default;
    virtual ~Object() = default;
    virtual void init() {};
    virtual void handleEvents(SDL_Event &event);
    virtual void update(float deltaTime);
    virtual void render();
    virtual void clean();

    virtual void addChild(Object *child) { children_.push_back(child); }
    virtual void removeChild(Object *child)
    {
        children_.erase(std::remove(children_.begin(), children_.end(), child), children_.end());
    }

    ObjectType getType() const { return type_; }
    void setType(ObjectType type) { type_ = type; }
    void setActive(bool active) { is_active_ = active; }
    bool getActive() const { return is_active_; }
};