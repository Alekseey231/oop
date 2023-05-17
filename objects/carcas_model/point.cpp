#include <cmath>
#include <point.h>

Point::Point(const double x, const double y, const double z) : value_x(x), value_y(y), value_z(z)
{}

double Point::x() const noexcept
{
    return this->value_x;
}

double Point::y() const noexcept
{
    return this->value_z;
}

double Point::z() const noexcept
{
    return this->value_z;
}

void Point::set_x(const double x) noexcept
{
    this->value_x = x;
}
void Point::set_y(const double y) noexcept
{
    this->value_y = y;
}
void Point::set_z(const double z) noexcept
{
    this->value_z = z;
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
    return Point(this->x() + point.x(), this->y()+point.y(), this->z()+point.z());
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

//Возможно лучше сразу хранить в матрице, чем каждый раз создавать....?
//подумать над оптимизацией передачи матриц
Matrix<double> Point::transform(const Matrix<double> &matrix)
{
    Matrix<double> local_coordinate = {{this->x(), this->y(), this->z()}};
    return local_coordinate * matrix;
}