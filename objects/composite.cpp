#include "composite.h"
#include <iostream>

std::size_t Composite::object_id = 1;

std::size_t Composite::add_object(const std::shared_ptr<BaseObject> &object)
{
    this->objects[this->object_id++] = object;
    return this->object_id - 1;
}

//мб здесь надо переопределить исключение на свое, если айди кривой
std::shared_ptr<BaseObject> Composite::get_object(std::size_t obj_id)
{
    auto obj = this->objects.find(obj_id);
    std::shared_ptr<BaseObject> result{nullptr};
    if (obj == this->objects.end())
    {
        for (auto it = this->objects.begin(); result == nullptr and it != this->objects.end(); ++it)
        {
            auto object = it->second;
            if (object->is_composite())
            {
                result = object->get_object(obj_id);
            }
        }
    }
    else
    {
        result = obj->second;
    }
    return result;
}

bool Composite::remove_object(std::size_t obj_id)
{
    bool result = false;

    auto delete_object = this->objects.find(obj_id);
    if (delete_object == this->objects.end())
    {
        for (auto it = this->objects.begin(); !result and it != this->objects.end(); ++it)
        {
            auto object = it->second;
            if (object->is_composite())
            {
                result = object->remove_object(obj_id);
            }
        }
    }
    else
    {
        this->objects.erase(delete_object);
        result = true;
    }
    return result;
}

void Composite::accept(Visitor &v)
{
    v.visit(*this);
}
