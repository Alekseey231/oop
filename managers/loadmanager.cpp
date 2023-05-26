#include "loadmanager.h"
#include "managersolution.h"

std::size_t LoadManager::load(const std::string &name)
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    auto scene = manager_scene->get_scene();
    auto model = _moderator->load(name);
    return scene->add_object(model);
}

void LoadManager::setModerator(std::shared_ptr<BaseLoadModerator> m)
{
    _moderator = m;
}

std::shared_ptr<LoadManager> LoadManagerCreator::get()
{
    if (!this->manager)
    {
        this->manager = create();
    }
    return this->manager;
}

std::shared_ptr<LoadManager> LoadManagerCreator::create()
{
    static auto singl = std::make_shared<LoadManager>();
    return singl;
}
