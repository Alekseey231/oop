#ifndef MANAGERSOLUTION_H
#define MANAGERSOLUTION_H

#include "cameramanager.h"
#include "drawmanager.h"
#include "loadmanager.h"
#include "scenemanager.h"
#include "transformmanager.h"
#include <memory>

class ManagerSolution
{
  public:
    ManagerSolution();
    static std::shared_ptr<SceneManager> get_scene_manager();
    static std::shared_ptr<TransformManager> get_transform_manager();
    static std::shared_ptr<DrawManager> get_draw_manager();
    static std::shared_ptr<CameraManager> get_camera_manager();
    static std::shared_ptr<LoadManager> get_load_manager();
};

#endif // MANAGERSOLUTION_H
