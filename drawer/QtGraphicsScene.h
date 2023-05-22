#ifndef QT_GRAPHICS_SCENE_H
#define QT_GRAPHICS_SCENE_H

#include "BaseGraphicsScene.h"
#include <QGraphicsScene>

class QtGraphicsScene : public BaseGraphicsScene
{
  public:
    QtGraphicsScene() = delete;
    explicit QtGraphicsScene(std::weak_ptr<QGraphicsScene> &current_scene) : scene(current_scene){};
    void clear() override;
    void draw_line(float x1, float y1, float x2, float y2) override;

  private:
    std::weak_ptr<QGraphicsScene> scene;
};

#endif
