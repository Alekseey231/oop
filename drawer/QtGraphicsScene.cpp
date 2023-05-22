#include "QtGraphicsScene.h"

void QtGraphicsScene::draw_line(float x1, float y1, float x2, float y2)
{
    this->scene.lock()->addLine(x1, y1, x2, y2);
}

void QtGraphicsScene::clear()
{
    scene.lock()->clear();
}
