#include "drawvisitor.h"
#include "../objects/composite.h"
#include "../scene/scene.h"
#include <stdlib.h>

DrawVisitor::DrawVisitor(std::shared_ptr<BaseCamera> cam, std::shared_ptr<BaseGraphicsScene> sc)
    : scene(std::move(sc)), camera(std::move(cam))
{
}

void DrawVisitor::visit(BaseCamera &camera)
{
}

void DrawVisitor::visit(Scene &scene)
{
    scene.accept(*this);
}

void DrawVisitor::visit(Composite &composite)
{
    //отображение группы объектов по настройкам из композита
    Matrix4 d = composite.get_transform_matrix();
    this->add_transform(d);
    for (auto &elem : composite)
    {
        elem.second->accept(*this);
    }
    add_transform(inverse(d));
}

void DrawVisitor::visit(CarcasModel &m)
{
    const auto model = m.base;
    const auto model_matrix = m.get_transform_matrix();
    const auto vertices = model->get_points();
    Matrix4 view_matrix = camera->get_view_matrix();
    Matrix4 proj_matrix = camera->get_projection_matrix();
    Matrix4 matr = proj_matrix * (view_matrix * model_matrix);
    for (const auto &line : model->get_edges())
    {
        Point v1 = matr * vertices[line.start()];
        Point v2 = matr * vertices[line.start()];
        scene->draw_line(v1[0], v1[1], v2[0], v2[1]);
    }
}

void DrawVisitor::clear_transform()
{
    context = Matrix4(1.0f);
}

void DrawVisitor::add_transform(const Matrix4 &matrix)
{
    context = context * matrix;
}
