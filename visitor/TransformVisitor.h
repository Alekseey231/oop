#ifndef TRANSFROMVISITOR_H
#define TRANSFROMVISITOR_H

#include "../objects/BaseObject.h"
#include "BaseVisitor.h"
#include "math/transformation.h"

class TransformVisitor : public Visitor
{
  protected:
    explicit TransformVisitor(float x, float y, float z) : data(x, y, z){};
    Vector3 data{0, 0, 0};
};

class RotateVisitor : public TransformVisitor
{
  public:
    explicit RotateVisitor(float x, float y, float z) : TransformVisitor(x, y, z){};
    virtual void visit(Camera &camera) override;
    virtual void visit(CarcasModel &object) override;
    virtual void visit(BaseObject &object) override;
    virtual void visit(Composite &composite) override{};
    virtual void visit(Scene &scene) override{};
    virtual void visit(BaseCamera &camera) override{};
};

class TranslateVisitor : public TransformVisitor
{
  public:
    explicit TranslateVisitor(float x, float y, float z) : TransformVisitor(x, y, z){};
    virtual void visit(Camera &object) override;
    virtual void visit(CarcasModel &object) override;
    virtual void visit(BaseObject &object) override;
    virtual void visit(Composite &composite) override;
    virtual void visit(Scene &scene) override;
    virtual void visit(BaseCamera &camera) override;
};

class ScaleVisitor : public TransformVisitor
{
  public:
    explicit ScaleVisitor(float x, float y, float z) : TransformVisitor(x, y, z){};
    virtual void visit(Camera &object) override;
    virtual void visit(CarcasModel &object) override;
    virtual void visit(BaseObject &object) override;
    virtual void visit(Composite &composite) override{};
    virtual void visit(Scene &scene) override{};
    virtual void visit(BaseCamera &camera) override{};
};

#endif // TRANSFROMVISITOR_H
