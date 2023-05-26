#include "CarcasModelSourceSolution.h"
#include <initializer_list>
#include <stdlib.h>

CarcasModelSourceSolution::CarcasModelSourceSolution(std::initializer_list<std::pair<std::size_t, CreateCreator>> list)
{
    for (auto &&elem : list)
        this->registration(elem.first, elem.second);
}

bool CarcasModelSourceSolution::registration(size_t id, CreateCreator createfun)
{
    return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

std::unique_ptr<CarcasModelSourceCreator> CarcasModelSourceSolution::create(size_t id)
{
    CallBackMap::const_iterator it = callbacks.find(id);

    if (it == callbacks.end())
    {
        // throw IdError();
    }

    return std::unique_ptr<CarcasModelSourceCreator>(it->second());
}
