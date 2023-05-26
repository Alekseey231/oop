#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "../math/glm_wrapped.h"
#include <memory>
#include <stdlib.h>

class TransformManager
{
  public:
    TransformManager() = default;

    void move(std::size_t object_id, const Vector3 &param) const;
    void rotate(std::size_t object_id, const Vector3 &param) const;
    void scale(std::size_t object_id, const Vector3 &param) const;
};

class TransformManagerCreator
{
  public:
    std::shared_ptr<TransformManager> get();

  protected:
    std::shared_ptr<TransformManager> create();
    std::shared_ptr<TransformManager> manager{nullptr};
};

#endif // TRANSFORMMANAGER_H
