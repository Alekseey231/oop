#include "drawmanager.h"
#include "managersolution.h"
#include "visitor/drawvisitor.h"

void DrawManager::draw_scene()
{
    //Мб и исключение кидать?
    //Мб нужна проверка, что объект действительно камера?
    if (!this->graphics_scene)
        return;
    this->graphics_scene->clear();
    auto manager_scene = ManagerSolution::get_scene_manager();
    auto manager_camera = ManagerSolution::get_camera_manager();
    auto scene = manager_scene->get_scene();
    auto camera_id = manager_camera->get_active_camera();
    auto cam = scene->get_object(camera_id);
    //возможно надо проверить, что это реально камера
    auto camera = std::dynamic_pointer_cast<BaseCamera>(cam);
    if (!camera)
    {
        // throw
    }

    DrawVisitor v(camera, this->graphics_scene);
    scene->accept(v);
}
void DrawManager::set_scene(std::shared_ptr<BaseGraphicsScene> &s)
{
    this->graphics_scene = s;
}

std::shared_ptr<DrawManager> DrawManagerCreator::get()
{
    if (!this->manager)
    {
        this->manager = create();
    }
    return this->manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::create()
{
    static auto singl = std::make_shared<DrawManager>();
    return singl;
}
