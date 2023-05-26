#include <cstddef>
#include <memory>

#include "base_command.h"

class ObjectCommand : public BaseCommand
{
};

class MoveObject : public ObjectCommand
{
    using Action = void (TransformManager::*)(std::size_t object_id, const Vector3 &param) const;

  public:
    MoveObject(std::size_t object_id, const Vector3 &param);

    virtual void execute() override;

  private:
    std::size_t id;
    Vector3 param;
    Action _method;
};

class ScaleObject : public ObjectCommand
{
    using Action = void (TransformManager::*)(std::size_t object_id, const Vector3 &param) const;

  public:
    ScaleObject(std::size_t object_id, const Vector3 &param);

    virtual void execute() override;

  private:
    std::size_t id;
    Vector3 param;
    Action _method;
};

class RotateObject : public ObjectCommand
{
    using Action = void (TransformManager::*)(std::size_t object_id, const Vector3 &param) const;

  public:
    RotateObject(std::size_t object_id, const Vector3 &param);

    virtual void execute() override;

  private:
    std::size_t id;
    Vector3 param;
    Action _method;
};
