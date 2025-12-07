#pragma once
#include "object_screen.h"

class ObjectAffiliate : public Object
{
protected:
    ObjectScreen *parent_ = nullptr;
    glm::vec2 offset_ = glm::vec2(0, 0);
    glm::vec2 size_ = glm::vec2(0, 0);

public:
    ObjectScreen *GetParent() const { return parent_; }
    void SetParent(ObjectScreen *parent) { parent_ = parent; }

    glm::vec2 GetOffset() const { return offset_; }
    void SetOffset(const glm::vec2 &offset) { offset_ = offset; }

    glm::vec2 GetSize() const { return size_; }
    void SetSize(const glm::vec2 &size) { size_ = size; }
};
