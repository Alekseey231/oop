#ifndef CARCAS_MODEL
#define CARCAS_MODEL

#include "../../../visitor/BaseVisitor.h"
#include "../BaseModel.h"
#include "figure.h"

#include <iostream>
#include <memory>
#include <stdlib.h>

class DrawVisitor;

class CarcasModel : public BaseModel
{
  public:
    explicit CarcasModel(std::shared_ptr<Figure> figure) : base(std::move(figure)){};
    ~CarcasModel() override = default;
    void accept(Visitor &v) override
    {
        v.visit(*this);
    };

  private:
    friend class DrawVisitor;
    std::shared_ptr<Figure> base;
};

#endif
