#include "player.h"
#include "core/scene.h"

void Player::init()
{
    Actor::init();
    max_speed_ = 500.0f;
    sprite_idle_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-idle.png", 2.0f);
    sprite_move_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-move.png", 2.0f);
    // sprite_idle_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/idle.png", 1.0f);
    // sprite_move_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/run.png", 1.0f);
    sprite_move_->setActive(false);
}

void Player::handleEvents(SDL_Event &event)
{
}

void Player::update(float deltaTime)
{
    Actor::update(deltaTime);
    keyboardControl();
    checkStates();
    move(deltaTime);
    syncCamera();
}

void Player::render()
{
    Actor::render();
}
void Player::clean()
{
    Actor::clean();
}

void Player::keyboardControl()
{
    velocity_ *= 0.9f;
    if (glm::length(velocity_) < 0.1f)
        velocity_ = glm::vec2(0.0f, 0.0f);

    auto currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_W])
    {
        is_move_up_ = true;
    }
    else
    {
        is_move_up_ = false;
    }
    if (currentKeyStates[SDL_SCANCODE_S])
    {
        is_move_down_ = true;
    }
    else
    {
        is_move_down_ = false;
    }

    if (currentKeyStates[SDL_SCANCODE_A])
    {
        is_move_left_ = true;
    }
    else
    {
        is_move_left_ = false;
    }
    if (currentKeyStates[SDL_SCANCODE_D])
    {
        is_move_right_ = true;
    }
    else
    {
        is_move_right_ = false;
    }
}

void Player::move(float deltaTime)
{
    int dir_x = is_move_right_ - is_move_left_;
    int dir_y = is_move_down_ - is_move_up_;
    double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
    if (len_dir != 0)
    {
        velocity_ = glm::vec2(dir_x / len_dir, dir_y / len_dir) * max_speed_;
    }

    setPosition(position_ + velocity_ * deltaTime);
    position_ = glm::clamp(position_, glm::vec2(0), game_.getCurrentScene()->getWorldSize());
}

void Player::syncCamera()
{
    game_.getCurrentScene()->setCameraPosition(position_ - game_.getScreenSize() / 2.0f);
}

void Player::checkStates()
{
    if (velocity_.x < 0)
    {
        sprite_idle_->setFlip(true);
        sprite_move_->setFlip(true);
    }
    else if (velocity_.x > 0)
    {
        sprite_idle_->setFlip(false);
        sprite_move_->setFlip(false);
    }

    bool new_is_moving = glm::length(velocity_) > 0.1f;
    if(new_is_moving != is_moving_)
    {
        is_moving_ = new_is_moving;
        changeState(is_moving_);
    }
}

void Player::changeState(bool is_moving)
{
    if(is_moving)
    {
        sprite_idle_->setActive(false);
        sprite_move_->setActive(true);
        sprite_move_->setCurrentFrame(sprite_idle_->getCurrentFrame());
        sprite_move_->setFrameTimer(sprite_idle_->getFrameTimer());
    }
    else
    {
        sprite_idle_->setActive(true);
        sprite_move_->setActive(false);
        sprite_idle_->setCurrentFrame(sprite_move_->getCurrentFrame());
        sprite_idle_->setFrameTimer(sprite_move_->getFrameTimer());
    }
}
