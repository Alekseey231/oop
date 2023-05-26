#include "ModelBuilder.h"

void ModelBuilder::build()
{
    _model = std::make_shared<Figure>();
}


void ModelBuilder::buildPoint(const Point &point)
{
    if (!isBuild()) { }

    _model->addPoint(point);
}


void ModelBuilder::buildEdge(const Edge &edge)
{
    if (!isBuild()) { }

    _model->addEdge(edge);
}


bool ModelBuilder::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<CarcasModel> ModelBuilder::get()
{
    return std::make_shared<CarcasModel>(CarcasModel(_model));
}
