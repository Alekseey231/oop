#include "base_command.h"

void setManagers(std::shared_ptr<DrawManager> drawManager, std::shared_ptr<LoadManager> loadManager,
                             std::shared_ptr<SceneManager> sceneManager,
                             std::shared_ptr<TransformManager> transformManager,
                             std::shared_ptr<CameraManager> cameraManager,
                             std::shared_ptr<ModelLoadModerator> modelLoadModerator)
{


    _drawManager = drawManager
    _loadManager = loadManager
    _sceneManager = sceneManager
    _cameraManager = transformManager;
    _transformManager = cameraManager;
    _modelLoadModerator = modelLoadModerator;
}
