#pragma once
#include <unordered_map>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include "glm/glm.hpp"

class AssetStore
{
private:
    SDL_Renderer *renderer_;
    std::unordered_map<std::string, SDL_Texture *> textures_;
    std::unordered_map<std::string, Mix_Chunk *> sounds_;
    std::unordered_map<std::string, Mix_Music *> musics_;
    std::unordered_map<std::string, TTF_Font *> fonts_;

public:
    AssetStore(SDL_Renderer *renderer){renderer_=renderer;};
    ~AssetStore()=default;

    void clean();

    // 载入函数
    void loadImage(const std::string &file_path);
    void loadSound(const std::string &file_path);
    void loadMusic(const std::string &file_path);
    void loadFont(const std::string &file_path, int font_size);

    // 读取函数
    SDL_Texture *getImage(const std::string &file_path);
    Mix_Chunk *getSound(const std::string &file_path);
    Mix_Music *getMusic(const std::string &file_path);
    TTF_Font *getFont(const std::string &file_path, int font_size);
};