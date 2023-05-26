#include "scenemanager.h"

SceneManager::SceneManager() : scene(std::make_shared<Scene>())
{
}

void SceneManager::set_scene(const std::shared_ptr<Scene> &s)
{
    this->scene = s;
}

std::shared_ptr<Scene> SceneManager::get_scene() const
{
    return this->scene;
}

std::shared_ptr<BaseObject> SceneManager::get_object(std::size_t object_id)
{
    return scene->get_object(object_id);
}

std::size_t SceneManager::add_object(const std::shared_ptr<BaseObject> &object)
{
    return scene->add_object(object);
}

bool SceneManager::remove_object(std::size_t obj_id)
{
    return scene->remove_object(obj_id);
}

std::shared_ptr<SceneManager> SceneManagerCreator::get()
{
    if (!this->manager)
    {
        this->manager = create();
    }
    return this->manager;
}

std::shared_ptr<SceneManager> SceneManagerCreator::create()
{
    static auto singl = std::make_shared<SceneManager>();
    return singl;
}
