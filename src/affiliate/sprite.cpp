#include "sprite.h"

Texture::Texture(const std::string &file_path)
{
    texture = Game::GetInstance().getAssetStore()->getImage(file_path);
    SDL_GetTextureSize(texture, &src_rect.w, &src_rect.h);
}

void Sprite::render()
{
    if (texture_.texture == nullptr)
    {
        return;
    }
    if (parent_ == nullptr)
    {
        return;
    }
    auto pos = parent_->getRenderPosition() + offset_;
    Game::GetInstance().renderTexture(texture_, pos, size_);
}

void Sprite::setTexture(const Texture &texture)
{
    texture_ = texture;
    size_=glm::vec2(texture_.src_rect.w, texture_.src_rect.h);
}
