#ifndef CAMERA_H
#define CAMERA_H

#include "../../math/glm_wrapped.h"
#include "./BaseCamera.h"

class RotateVisitor;
class ScaleVisitor;
class TranslateVisitor;

class Camera : public BaseCamera
{
  public:
    static const float YAW;
    static const float PITCH;
    Camera(const Vector3 &pos = Vector3(0, 0, 0), const Vector3 &up = Vector3(0, 1, 0), float yaw = YAW,
           float pitch = PITCH);
    ~Camera() override = default;

    void accept(Visitor &v) override;
    Matrix4 get_view_matrix() const override;
    Matrix4 get_projection_matrix() const override;

  protected:
    friend RotateVisitor;
    friend ScaleVisitor;
    friend TranslateVisitor;

    Vector3 Front;
    Vector3 Up;
    Vector3 Right;
    Vector3 WorldUp;

    float Yaw;
    float Pitch;
    float aspect = 1.0f;
    float zNear = 0.1f;
    float zFar = 100.0f;

    void update_camera_vectors();
};

#endif
