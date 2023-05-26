#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H

#include "../objects/visible_object/carcas_model/CarcasModel.h"
#include "../objects/visible_object/carcas_model/figure.h"
#include "BaseBuilder.h"
#include "BaseCreator.h"

class BaseModelBuilder : public BaseBuilder
{
  public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() = default;

    virtual void build() override = 0;
    virtual void buildPoint(const Point &point) = 0;
    virtual void buildEdge(const Edge &edge) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<CarcasModel> get() = 0;

  protected:
    std::shared_ptr<Figure> _model;
};

#endif // BASEBUILDER_H
