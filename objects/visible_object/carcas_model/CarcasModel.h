#ifndef CARCAS_MODEL
#define CARCAS_MODEL

#include "figure.h"
#include "BaseVisitor.h"
#include "BaseModel.h"

#include <stdlib.h>
#include <memory>

class CarcasModel : BaseModel
{
    public:
        explicit CarcasModel(std::shared_ptr<Figure> figure) : base(std::move(figure)) {};
        ~CarcasModel() override = default;
        void accept(Visitor& v) override {v.visit(*this);};
    private:
        std::shared_ptr<Figure> base;
};

#endif