#include "asset_store.h"

void AssetStore::clean()
{
    for (auto &texture : textures_)
    {
        SDL_DestroyTexture(texture.second);
    }
    textures_.clear();

    for (auto &sound : sounds_)
    {
        Mix_FreeChunk(sound.second);
    }
    sounds_.clear();

    for (auto &music : musics_)
    {
        Mix_FreeMusic(music.second);
    }
    musics_.clear();

    for (auto &font : fonts_)
    {
        TTF_CloseFont(font.second);
    }
    fonts_.clear();
}

void AssetStore::loadImage(const std::string &file_path)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer_, file_path.c_str());
    if (texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load image: %s", file_path.c_str());
        return;
    }
    // textures_[file_path] = texture;//如果已经存在，会覆盖之前的值
    textures_.emplace(file_path, texture); // 如果已经存在，不会覆盖之前的值
}

void AssetStore::loadSound(const std::string &file_path)
{
    Mix_Chunk *chunk = Mix_LoadWAV(file_path.c_str());
    if (chunk == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load sound: %s", file_path.c_str());
        return;
    }

    sounds_.emplace(file_path, chunk);
}

void AssetStore::loadMusic(const std::string &file_path)
{
    Mix_Music *music = Mix_LoadMUS(file_path.c_str());
    if (music == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load music: %s", file_path.c_str());
        return;
    }

    musics_.emplace(file_path, music);
}

void AssetStore::loadFont(const std::string &file_path, int font_size)
{
    TTF_Font *font = TTF_OpenFont(file_path.c_str(), font_size);
    if (font == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font: %s", file_path.c_str());
        return;
    }

    fonts_.emplace(file_path + std::to_string(font_size), font);
}

SDL_Texture *AssetStore::getImage(const std::string &file_path)
{
    auto iter = textures_.find(file_path);
    if (iter == textures_.end())
    {
        loadImage(file_path);
    }
    iter = textures_.find(file_path);
    if (iter == textures_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture: %s", file_path.c_str());
        return nullptr;
    }
    return iter->second;
}

Mix_Chunk *AssetStore::getSound(const std::string &file_path)
{
    auto iter = sounds_.find(file_path);
    if (iter == sounds_.end())
    {
        loadSound(file_path);
    }
    iter = sounds_.find(file_path);
    if (iter == sounds_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load sound: %s", file_path.c_str());
        return nullptr;
    }
    return iter->second;
}

Mix_Music *AssetStore::getMusic(const std::string &file_path)
{
    auto iter = musics_.find(file_path);
    if (iter == musics_.end())
    {

        loadMusic(file_path);
    }
    iter = musics_.find(file_path);
    if (iter == musics_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load music: %s", file_path.c_str());
        return nullptr;
    }
    return iter->second;
}

TTF_Font *AssetStore::getFont(const std::string &file_path, int font_size)
{
    auto iter = fonts_.find(file_path + std::to_string(font_size));
    if (iter == fonts_.end())
    {
        loadFont(file_path, font_size);
    }
    iter = fonts_.find(file_path + std::to_string(font_size));
    if (iter == fonts_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font: %s", file_path.c_str());
        return nullptr;
    }
    return iter->second;
}
