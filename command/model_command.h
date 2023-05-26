#include <cstddef>
#include <memory>

#include "base_command.h"

class ModelCommand : public BaseCommand { };

class MoveModel : public ModelCommand
{
    using Action = void(TransformManager::*)(std::size_t object_id, const Vector3 &param);
public:
    MoveModel(std::size_t object_id, const Vector3 &param);

    virtual void execute() override;

private:
    std::size_t id;
    Vector3 param;
    Action _method;
};


class ScaleModel : public ModelCommand
{
    using Action = void(TransformManager::*)(std::size_t object_id, const Vector3 &param);
public:
    ScaleModel(std::size_t object_id, const Vector3 &param);

    virtual void execute() override;

private:
    std::size_t id;
    Vector3 param;
    Action _method;
};



class RotateModel : public ModelCommand
{
    using Action = void(TransformManager::*)(std::size_t object_id, const Vector3 &param);
public:
    RotateModel(std::size_t object_id, const Vector3 &param);

    virtual void execute() override;

private:
    std::size_t id;
    Vector3 param;
    Action _method;
};

class RemoveModel : public ModelCommand
{
    using Action = void(SceneManager::*)(const size_t id);
public:
    RemoveModel(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
    Action _method;
};

class AddModel: public ModelCommand
{
    using Action = std::size_t(SceneManager::*)(const shared_ptr<BaseObject> &object);
public:
    AddModel(ID &id, shared_ptr<BaseObject> object);

    virtual void execute() override;
private:
    ID &_id;
    std::shared_ptr<BaseObject> _object;

    Action _method;
};

class LoadModel : public ModelCommand
{
    using Action = std::shared_ptr<BaseObject>(LoadManager::*)(std::string &name);
public:
    LoadModel(std::shared_ptr<BaseObject> &object, std::string &fileName);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> &_object;
    std::string _fileName;

    Action _method;
};
