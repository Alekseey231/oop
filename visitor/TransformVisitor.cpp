#include "TransformVisitor.h"
#include "../objects/invisible_object/Camera.h"
#include "../objects/visible_object/carcas_model/CarcasModel.h"
#include <iostream>

void RotateVisitor::visit(CarcasModel &object)
{
    object.transform = std::make_shared<Transformation>(*object.transform + Rotation(data[0], data[1], data[2]));
}

void RotateVisitor::visit(Camera &object)
{
    object.Yaw += data[0];
    object.Pitch += data[1];
    if (object.Pitch > 44.0f)
        object.Pitch = 44.0f;
    if (object.Pitch < -44.0f)
        object.Pitch = -44.0f;
    object.update_camera_vectors();
}

void RotateVisitor::visit(BaseObject &object)
{
}

void ScaleVisitor::visit(CarcasModel &object)
{
    object.transform = std::make_shared<Transformation>(*object.transform + Scale(data[0], data[1], data[2]));
}

void ScaleVisitor::visit(Camera &object)
{
}

void ScaleVisitor::visit(BaseObject &object)
{
}

void TranslateVisitor::visit(CarcasModel &object)
{
    std::cout << "Hehehehe\n";
    object.transform = std::make_shared<Transformation>(*object.transform + Translation(data[0], data[1], data[2]));
}

void TranslateVisitor::visit(Camera &object)
{
    object.transform = std::make_shared<Transformation>(*object.transform + Translation(data[0], data[1], data[2]));
}

void TranslateVisitor::visit(BaseObject &object)
{
}

void TranslateVisitor::visit(Composite &composite)
{
}
void TranslateVisitor::visit(Scene &scene)
{
}
void TranslateVisitor::visit(BaseCamera &camera)
{
}
