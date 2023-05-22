#include "composite.h"

Composite::Composite(std::shared_ptr<BaseObject> first, ...)
{
    for(std::shared_ptr<BaseObject> *ptr = &first; *ptr; ++ptr)
    {
        this->objects.push_back(*ptr);
    }
}

std::size_t Composite::add_object(const std::shared_ptr<BaseObject> &object)
{
    this->objects.push_back(object);
}

std::shared_ptr<BaseObject> Composite::get_object(std::size_t object_id)
{
    this->objects.at(object_id);
}

void Composite::remove_object(std::size_t object_id)
{

}
