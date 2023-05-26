#include "./Camera.h"
#include "../../math/glm_wrapped.h"
#include "../../math/math.h"
#include "../../visitor/TransformVisitor.h"

const float Camera::YAW = -90.0f;
const float Camera::PITCH = 0;

void Camera::accept(Visitor &v)
{
    v.visit(*this);
}

Camera::Camera(const Vector3 &pos, const Vector3 &up, float yaw, float pitch)
    : Front(Vector3(0.0f, 0.0f, -1.0f)), WorldUp(up), Yaw(yaw), Pitch(pitch)
{
    TranslateVisitor v(pos.x, pos.y, pos.z);
    v.visit(*this);
    this->update_camera_vectors();
}

Matrix4 Camera::get_view_matrix() const
{
    auto pos = this->transform->get_pos();
    return lookAt(pos, pos + this->Front, this->Up);
}

Matrix4 Camera::get_projection_matrix() const
{
    return perspective(radians(45.0f), this->aspect, this->zNear, this->zFar);
}

void Camera::update_camera_vectors()
{
    Vector3 front;
    front.x = cos(radians(Yaw)) * cos(radians(Pitch));
    front.y = sin(radians(Pitch));
    front.z = sin(radians(Yaw)) * cos(radians(Pitch));
    Front = normalize(front);
    Right = normalize(cross(Front, WorldUp)); // normalize the vectors, because their length gets closer to 0 the more
                                              // you look up or down which results in slower movement.
    Up = normalize(cross(Right, Front));
}
