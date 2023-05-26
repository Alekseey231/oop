#include "SolutionModelLoadModerator.h"

std::shared_ptr<ModelLoadModerator> ModeratorSolution::create()
{
    return ModelLoadModeratorCreator().createModerator();
}


/*SolutionModerator::SolutionModerator(std::initializer_list<std::pair<size_t, CreateCreator>> list)
{
    for (auto &&elem : list)
        this->registration(elem.first, elem.second);
}

bool SolutionModerator::registration(size_t id, CreateCreator createfun)
{
    return this->callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

std::unique_ptr<BaseLoadModeratorCreator> SolutionModerator::create(const std::size_t id)
{
    CallBackMap::const_iterator it = this->callbacks.find(id);
    if (it == this->callbacks.end())
    {
        // throw
    }
    return std::unique_ptr<BaseLoadModeratorCreator>(it->second());
}*/
