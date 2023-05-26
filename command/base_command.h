#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include "load/SolutionModelLoadModerator.h"
#include "managers/managersolution.h"

class BaseCommand
{
  public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void setManagers(std::shared_ptr<DrawManager> drawManager, std::shared_ptr<LoadManager> loadManager,
                             std::shared_ptr<SceneManager> sceneManager,
                             std::shared_ptr<TransformManager> transformManager,
                             std::shared_ptr<CameraManager> cameramManager,
                             std::shared_ptr<ModelLoadModerator> modelLoadModerator);

    virtual void execute() = 0;

  protected:
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<CameraManager> _cameraManager;
    std::shared_ptr<TransformManager> _transformManager;
    std::shared_ptr<ModelLoadModerator> _modelLoadModerator;
};

#endif
