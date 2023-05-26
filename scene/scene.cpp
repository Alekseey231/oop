#include "scene.h"
#include "../objects/BaseObject.h"

std::size_t Scene::add_object(const std::shared_ptr<BaseObject> &object)
{
    return this->objects.add_object(object);
}

bool Scene::remove_object(std::size_t object_id)
{
    return this->objects.remove_object(object_id);
}

std::shared_ptr<BaseObject> Scene::get_object(std::size_t object_id)
{
    return this->objects.get_object(object_id);
}

void Scene::accept(Visitor &v)
{
    this->objects.accept(v);
}
