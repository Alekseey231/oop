#include "CameraSolution.h"

Solution::Solution(std::initializer_list<std::pair<size_t, CreateCreator>> list)
{
    for (auto &&elem : list)
        this->registration(elem.first, elem.second);
}

bool Solution::registration(size_t id, CreateCreator createfun)
{
    return this->callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

std::unique_ptr<BaseCameraCreator> Solution::create(const std::size_t id)
{
    CallBackMap::const_iterator it = this->callbacks.find(id);
    if (it == this->callbacks.end())
    {
        // throw
    }
    return std::unique_ptr<BaseCameraCreator>(it->second());
}
