#ifndef SOLUTIONMODELLOADMODERATOR_H
#define SOLUTIONMODELLOADMODERATOR_H

#include "BaseLoadModerator.h"
#include <map>
#include <stdlib.h>
#include "BaseBuilder.h"
#include "BaseDirector.h"
#include "BaseLoader.h"
#include <vector>
#include "BaseCreator.h"
#include "ModelLoadModerator.h"


class ModeratorSolution
{
  public:
    ModeratorSolution() = default;
    static std::shared_ptr<ModelLoadModerator> create();
};

/*class SolutionModerator
{
    using CreateCreatorModerator = std::unique_ptr<BaseLoadModeratorCreator> (&)();
    using CreateCreatorDirector = std::unique_ptr<BaseDirectorCreator> (&)();
    using CreateCreatorBuilder = std::unique_ptr<BaseBuilderCreator> (&)();
    using CreateCreatorLoader = std::unique_ptr<BaseModelLoaderCreator> (&)();
    using BaseCreator = std::unique_ptr<BaseModelLoaderCreator> (&)();

  public:
    SolutionModerator() = default;
    explicit SolutionModerator(std::initializer_list<std::pair<std::size_t, std::vector<BaseCreator>> list);

    bool registration(std::size_t id, CreateCreator createfun);
    bool check(std::size_t id)
    {
        return this->callbacks.erase(id) == 1;
    };

    std::unique_ptr<BaseLoadModeratorCreator> create(const std::size_t id);

  private:
    CallBackMap callbacks;
};*/


#endif // SOLUTIONMODELLOADMODERATOR_H
