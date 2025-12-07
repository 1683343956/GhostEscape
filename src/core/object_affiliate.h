#pragma once
#include "object_screen.h"

class ObjectAffiliate : public Object
{
protected:
    ObjectScreen *parent_ = nullptr;
    glm::vec2 offset_ = glm::vec2(0, 0);
    glm::vec2 size_ = glm::vec2(0, 0);

public:
    ObjectScreen *getParent() const { return parent_; }
    void setParent(ObjectScreen *parent) { parent_ = parent; }

    glm::vec2 getOffset() const { return offset_; }
    void setOffset(const glm::vec2 &offset) { offset_ = offset; }

    glm::vec2 getSize() const { return size_; }
    void setSize(const glm::vec2 &size) { size_ = size; }
};
