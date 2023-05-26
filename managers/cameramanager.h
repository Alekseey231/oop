#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "../objects/invisible_object/CameraSolution.h"
#include <memory>
#include <stdlib.h>

class CameraManager
{
  public:
    CameraManager();
    void set_active_camera(std::size_t id);
    std::size_t get_active_camera();
    std::size_t create_new_camera(std::size_t id, const Vector3 &pos);
    bool remove_camera(std::size_t id);

  private:
    std::size_t active_camera = 0;
    std::size_t count_camera = 1;
    std::shared_ptr<Solution> solution{nullptr};
};

class CameraManagerCreator
{
  public:
    std::shared_ptr<CameraManager> get();

  protected:
    std::shared_ptr<CameraManager> create();
    std::shared_ptr<CameraManager> manager{nullptr};
};

#endif // CAMERAMANAGER_H
