#pragma once
#include "object_world.h"

class Stats;
class Actor : public ObjectWorld
{
protected:
    Stats *stats_ = nullptr;               // 角色属性
    glm::vec2 velocity_ = glm::vec2(0, 0); // 速度
    float max_speed_ = 100.0f;             // 最大速度
public:
    virtual void move(float deltaTime);
    void setStats(Stats *stats) { stats_ = stats; }
    Stats *getStats() { return stats_; }
    void takeDamage(float damage);
    bool isAlive();
};
