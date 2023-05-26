#include "cameramanager.h"
#include "managersolution.h"
#include <memory>

//надо ли давать извне регистрировать что-то?
CameraManager::CameraManager()
{
    this->solution = std::make_shared<Solution>(Solution{{1, CrCreator::createConCreator<Camera>}});
}

void CameraManager::set_active_camera(std::size_t id)
{
    this->active_camera = id;
}

std::size_t CameraManager::get_active_camera()
{
    return this->active_camera;
}

std::size_t CameraManager::create_new_camera(std::size_t id, const Vector3 &pos)
{
    auto creator = this->solution->create(id);
    std::shared_ptr<BaseCamera> camera = creator->createCamera(pos);
    auto manager_scene = ManagerSolution::get_scene_manager();
    this->count_camera += 1;
    return manager_scene->add_object(camera);
}

bool CameraManager::remove_camera(std::size_t id)
{
    if (this->count_camera == 1)
    {
        // throw
    }
    auto manager_scene = ManagerSolution::get_scene_manager();
    bool is_remove = manager_scene->remove_object(id);
    if (is_remove)
    {
        this->count_camera -= 1;
    }
    return is_remove;
}

std::shared_ptr<CameraManager> CameraManagerCreator::get()
{
    if (!this->manager)
    {
        this->manager = create();
    }
    return this->manager;
}

std::shared_ptr<CameraManager> CameraManagerCreator::create()
{
    static auto singl = std::make_shared<CameraManager>();
    return singl;
}
