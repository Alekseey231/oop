#include "facade.h"

Facade::Facade()
{
    this->draw_manager = ManagerSolution::get_draw_manager();
    this->camera_manager = ManagerSolution::get_camera_manager();
    this->transform_manager = ManagerSolution::get_transform_manager();
    this->scene_manager = ManagerSolution::get_scene_manager();
    this->load_manager = ManagerSolution::get_load_manager();
    this->load_moderator = ModeratorSolution::create();

    this->load_manager->setModerator(this->load_moderator);
}

void Facade::execute(BaseCommand &command)
{
}
