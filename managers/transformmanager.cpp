#include "transformmanager.h"
#include "../visitor/TransformVisitor.h"
#include "managersolution.h"

void TransformManager::move(std::size_t object_id, const Vector3 &param) const
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    auto scene = manager_scene->get_scene();
    auto object = scene->get_object(object_id);
    TranslateVisitor v(param.x, param.y, param.z);
    object->accept(v);
}
void TransformManager::rotate(std::size_t object_id, const Vector3 &param) const
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    auto scene = manager_scene->get_scene();
    auto object = scene->get_object(object_id);
    RotateVisitor v(param.x, param.y, param.z);
    object->accept(v);
}
void TransformManager::scale(std::size_t object_id, const Vector3 &param) const
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    auto scene = manager_scene->get_scene();
    auto object = scene->get_object(object_id);
    ScaleVisitor v(param.x, param.y, param.z);
    object->accept(v);
}

std::shared_ptr<TransformManager> TransformManagerCreator::get()
{
    if (!this->manager)
    {
        this->manager = create();
    }
    return this->manager;
}

std::shared_ptr<TransformManager> TransformManagerCreator::create()
{
    static auto singl = std::make_shared<TransformManager>();
    return singl;
}
