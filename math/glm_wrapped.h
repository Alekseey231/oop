#ifndef GLM_WRAPPED_H
#define GLM_WRAPPED_H

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/trigonometric.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

using Vector3 = glm::vec3;
using Vector4 = glm::vec4;
using Matrix4 = glm::mat4;

Matrix4 translate(const Matrix4 &mat, const Vector3 &offset);
Matrix4 rotate(const Matrix4 &mat, float rad, const Vector3 &offset);
Matrix4 scale(const Matrix4 &mat, const Vector3 &scale);
Matrix4 lookAt(const Vector3 &pos, const Vector3 &eye, const Vector3 &dir);
Vector3 normalize(const Vector3 &vec);
Matrix4 perspective(float rad, float aspect, float zNear, float zFar);
Matrix4 inverse(const Matrix4 &matrix);

#endif
