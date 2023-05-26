#ifndef BASE_VISITOR_H
#define BASE_VISITOR_H

#include "math/glm_wrapped.h"

class BaseObject;
class CarcasModel;
class Camera;
class Composite;
class Scene;
class BaseCamera;

class Visitor
{
  public:
    // virtual void visit(CarcasModel &model) = 0;
    // virtual void visit(CarcasModel &model, float x, float y, float z) = 0;
    virtual void visit(BaseObject &object) = 0;
    virtual void visit(CarcasModel &object) = 0;
    virtual void visit(Camera &object) = 0;
    virtual void visit(Composite &composite) = 0;
    virtual void visit(Scene &scene) = 0;
    virtual void visit(BaseCamera &camera) = 0;
};

#endif
