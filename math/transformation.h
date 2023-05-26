#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <memory>
#include <utility>
#include "glm_wrapped.h"

class BaseTransformation
{
};

class Scale : public BaseTransformation
{
public:
    float x{1}, y{1}, z{1};
    Scale() = default;
    Scale(float x, float y, float z) : x(x), y(y), z(z) {};
    virtual ~Scale() = default;
    Scale operator +(const Scale &scale) const;
};

class Translation : public BaseTransformation
{
public:
    float x{}, y{}, z{};
    Translation() = default;
    Translation(float x, float y, float z) : x(x), y(y), z(z) {};
    virtual ~Translation() = default;
    Translation operator +(const Translation &other) const;
};

class Rotation : public BaseTransformation
{
public:
    float x{}, y{}, z{};
    Rotation() = default;
    Rotation(float x, float y, float z) : x(x), y(y), z(z) {};
    virtual ~Rotation() = default;
    Rotation operator +(const Rotation &other) const;
};

class Transformation : public BaseTransformation
{
private:
    Rotation rotation{};
    Translation translation{};
    Scale scale_{};
public:
    Transformation() = default;
    Transformation(const Transformation &other);
    Transformation(const Rotation &rotation_, const Translation &translation_, const Scale &scale_);
    virtual ~Transformation() = default;
    Matrix4 get_matrix() const;
    Transformation operator +(const Scale &scale) const;
    Transformation operator +(const Translation &other) const;
    Transformation operator +(const Rotation &other) const;
    Transformation operator +(const Transformation &other) const;
    Vector3 get_pos() const;
};

#endif // TRANSFORMATION_H
