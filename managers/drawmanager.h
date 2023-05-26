#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "../drawer/BaseGraphicsScene.h"
#include <memory>

class DrawManager
{
  public:
    DrawManager() = default;
    DrawManager(const DrawManager &) = delete;
    DrawManager &operator=(const DrawManager &) = delete;

    ~DrawManager() = default;

    void draw_scene();
    void set_scene(std::shared_ptr<BaseGraphicsScene> &s);

  private:
    std::shared_ptr<BaseGraphicsScene> graphics_scene;
};

class DrawManagerCreator
{
  public:
    std::shared_ptr<DrawManager> get();

  protected:
    std::shared_ptr<DrawManager> create();
    std::shared_ptr<DrawManager> manager{nullptr};
};

#endif // DRAWMANAGER_H
