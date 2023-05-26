#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "../../math/glm_wrapped.h"
#include "./InvisibleObject.h"
#include "./visitor/BaseVisitor.h"

class BaseCamera : public InvisibleObject
{
  public:
    BaseCamera() = default;
    virtual ~BaseCamera() = default;

    virtual Matrix4 get_view_matrix() const = 0;
    virtual Matrix4 get_projection_matrix() const = 0;
};

class BaseCameraCreator
{
  public:
    virtual ~BaseCameraCreator() = default;
    virtual std::unique_ptr<BaseCamera> createCamera(const Vector3 &pos) = 0;
};

template <std::derived_from<BaseCamera> Tprod> class ConCameraCreator : public BaseCameraCreator
{
  public:
    std::unique_ptr<BaseCamera> createCamera(const Vector3 &pos) override
    {
        return std::make_unique<Tprod>(pos);
    }
};

class CrCreator
{
  public:
    template <typename Tprod> static std::unique_ptr<BaseCameraCreator> createConCreator()
    {
        return std::make_unique<ConCameraCreator<Tprod>>();
    }
};

#endif // BASECAMERA_H
