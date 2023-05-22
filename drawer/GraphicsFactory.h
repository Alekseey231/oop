#ifndef GRAPHICS_FACTORY_H
#define GRAPHICS_FACTORY_H

#include "BaseGraphicsScene.h"
#include <memory>
#include <stdlib.h>

class GraphicsFactory
{
  public:
    GraphicsFactory() = default;
    virtual ~GraphicsFactory() = default;
    virtual std::unique_ptr<BaseGraphicsScene> createScene() = 0;
};

#endif
