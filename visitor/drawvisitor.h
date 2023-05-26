#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "../drawer/BaseGraphicsScene.h"
#include "../objects/BaseObject.h"
#include "../objects/invisible_object/BaseCamera.h"
#include "../objects/visible_object/carcas_model/CarcasModel.h"
#include "../objects/visible_object/carcas_model/figure.h"

#include "../scene/scene.h"
#include "BaseVisitor.h"

class DrawVisitor : public Visitor
{
  public:
    DrawVisitor(std::shared_ptr<BaseCamera> cam, std::shared_ptr<BaseGraphicsScene> sc);
    virtual void visit(BaseCamera &camera) override;
    virtual void visit(Scene &scene) override;
    virtual void visit(CarcasModel &m) override;
    virtual void visit(Composite &composite) override;
    virtual void visit(Camera &camera) override{};
    virtual void visit(BaseObject &object) override{};

  private:
    std::shared_ptr<BaseGraphicsScene> scene;
    std::shared_ptr<BaseCamera> camera;
    Matrix4 context = Matrix4(1.0f);
    void add_transform(const Matrix4 &matrix);
    void clear_transform();
};

#endif // DRAWVISITOR_H
