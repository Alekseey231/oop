#ifndef QT_GRAPHICS_FACTORY_H
#define QT_GRAPHICS_FACTORY_H

#include "BaseGraphicsScene.h"
#include <memory>
#include <stdlib.h>

class QtGraphicsFactory
{
  public:
    QtGraphicsFactory() = default;
    virtual ~QtGraphicsFactory() = default;
    virtual std::unique_ptr<BaseGraphicsScene> createScene() = 0;
};

#endif
