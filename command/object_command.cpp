#include "object_command.h"

MoveObject::MoveObject(std::size_t object_id, const Vector3 &p) : id(object_id), param(p)
{
    _method = &TransformManager::move;
}

void MoveObject::execute()
{
    ((*_transformManager).*_method)(id, param);
}

RotateObject::RotateObject(std::size_t object_id, const Vector3 &p) : id(object_id), param(p)
{
    _method = &TransformManager::rotate;
}

void RotateObject::execute()
{
    ((*_transformManager).*_method)(id, param);
}

ScaleObject::ScaleObject(std::size_t object_id, const Vector3 &p) : id(object_id), param(p)
{
    _method = &TransformManager::scale;
}

void ScaleObject::execute()
{
    ((*_transformManager).*_method)(id, param);
}
