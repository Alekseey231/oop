#ifndef MODELLOADMODERATOR_H
#define MODELLOADMODERATOR_H

#include "BaseLoadModerator.h"
#include "BaseModelDirector.h"

class ModelLoadModerator : public BaseLoadModerator
{
  public:
    ModelLoadModerator() = default;
    explicit ModelLoadModerator(std::shared_ptr<BaseModelDirector> director);

    ~ModelLoadModerator() = default;

    std::shared_ptr<BaseObject> load(const std::string &fileName) override;

  private:
    std::shared_ptr<BaseModelBuilder> _builder;
    std::shared_ptr<BaseModelDirector> _director;
};

class ModelLoadModeratorCreator
{
  public:
    std::shared_ptr<ModelLoadModerator> createModerator();

  private:
    void createInstance();

    std::shared_ptr<ModelLoadModerator> _moderator;
};

#endif // MODELLOADMODERATOR_H
