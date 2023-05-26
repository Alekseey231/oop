#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../objects/BaseObject.h"
#include "../scene/scene.h"

class SceneManager
{
  public:
    SceneManager();
    SceneManager(const SceneManager &) = delete;
    SceneManager &operator=(const SceneManager &) = delete;

    ~SceneManager() = default;

    std::shared_ptr<Scene> get_scene() const;
    std::shared_ptr<BaseObject> get_object(std::size_t id);
    bool remove_object(std::size_t obj_id);
    std::size_t add_object(const std::shared_ptr<BaseObject> &object);
    void set_scene(const std::shared_ptr<Scene> &s);

  private:
    std::shared_ptr<Scene> scene;
};

class SceneManagerCreator
{
  public:
    std::shared_ptr<SceneManager> get();

  protected:
    std::shared_ptr<SceneManager> create();
    std::shared_ptr<SceneManager> manager{nullptr};
};

#endif // SCENEMANAGER_H
