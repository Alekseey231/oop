#ifndef QT_GRAPHICS_FACTORY_H
#define QT_GRAPHICS_FACTORY_H

#include "BaseGraphicsScene.h"
#include "GraphicsFactory.h"
#include <QGraphicsScene>
#include <memory>
#include <stdlib.h>

class QtGraphicsFactory : GraphicsFactory
{
  public:
    QtGraphicsFactory() = default;
    virtual ~QtGraphicsFactory() = default;
    std::unique_ptr<BaseGraphicsScene> createScene() override
    {
        // return QtGraphicsScene(scene);
        return nullptr;
    }
};

#endif
