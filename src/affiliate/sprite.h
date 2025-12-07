#pragma once
#include "../core/object_affiliate.h"
#include <string>

struct Texture
{
    SDL_Texture *texture = nullptr;
    SDL_FRect src_rect = {0, 0, 0, 0};
    float angle = 0;
    bool is_flip = false;
    Texture()=default;
    Texture(const std::string &file_path);
};

class Sprite : public ObjectAffiliate
{
protected:
    Texture texture_;

public:
    virtual void render() override;

    Texture getTexture() { return texture_; }
    void setTexture(const Texture &texture);
};