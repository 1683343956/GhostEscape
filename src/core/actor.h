#pragma once
#include "object_world.h"

class Actor : public ObjectWorld
{
protected:
    glm::vec2 velocity_ = glm::vec2(0, 0); // 速度
    float max_speed_ = 500.0f;             // 最大速度
};
