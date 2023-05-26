#ifndef FACADE_H
#define FACADE_H

#include "../command/base_command.h"
#include "../managers/cameramanager.h"
#include "../managers/drawmanager.h"
#include "../managers/managersolution.h"
#include "../managers/scenemanager.h"
#include "../managers/transformmanager.h"
#include "./load/ModelLoadModerator.h"
#include "./load/SolutionModelLoadModerator.h"

class Facade
{
  public:
    Facade();
    ~Facade() = default;

    void execute(BaseCommand &command);

  private:
    std::shared_ptr<DrawManager> draw_manager;
    std::shared_ptr<SceneManager> scene_manager;
    std::shared_ptr<TransformManager> transform_manager;
    std::shared_ptr<CameraManager> camera_manager;
    std::shared_ptr<LoadManager> load_manager;
    std::shared_ptr<ModelLoadModerator> load_moderator;
};

#endif // FACADE_H
