#include "point.h"
#include <cmath>
/*
Point::Point(const double x, const double y, const double z) : data({{x, y, z, 1}})
{
}

double Point::x() const noexcept
{
    return this->data[0][0];
}

double Point::y() const noexcept
{
    return this->data[0][1];
}

double Point::z() const noexcept
{
    return this->data[0][2];
}

void Point::set_x(const double x) noexcept
{
    this->data[0][0] = x;
}
void Point::set_y(const double y) noexcept
{
    this->data[0][1] = y;
}
void Point::set_z(const double z) noexcept
{
    this->data[0][2] = z;
}

bool Point::operator==(const Point &point) const noexcept
{
    return this->x() == point.x() and this->y() == point.y() and this->z() == point.z();
}

bool Point::is_equal(const Point &point) const noexcept
{
    return this->operator==(point);
}

Point Point::operator+(const Point &point) const
{
    return Point(this->x() + point.x(), this->y() + point.y(), this->z() + point.z());
}

Point Point::add(const Point &point) const
{
    return this->operator+(point);
}

Point Point::operator-() const
{
    return Point(-this->x(), -this->y(), -this->z());
}
Point Point::neg() const
{
    return this->operator-();
}

Point Point::operator-(const Point &point) const
{
    return this->operator+(-point);
}

Point Point::sub(const Point &point) const
{
    return this->operator-(point);
}

Matrix<double> Point::transform(const Matrix<double> &matrix)
{
    this->data = this->data * matrix;
}*/
