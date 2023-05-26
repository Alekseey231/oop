#ifndef SCENE_H
#define SCENE_H

#include "../objects/composite.h"

class Scene
{
  public:
    Scene() = default;
    virtual ~Scene() = default;

    std::size_t add_object(const std::shared_ptr<BaseObject> &object);
    bool remove_object(std::size_t object_id);
    std::shared_ptr<BaseObject> get_object(std::size_t object_id);
    void accept(Visitor &v);
    // метод count_obj?

  private:
    Composite objects;
};

#endif
