#ifndef POINT_H
#define POINT_H

#include "matrix/matrix/matrix.h"

/*class Point
{
  public:
    Point() = default;
    Point(const double x, const double y, const double z);

    Point(const Point &point) = default;

    Point &operator=(const Point &point) = default;

    ~Point() = default;

    double x() const noexcept;
    double y() const noexcept;
    double z() const noexcept;

    void set_x(const double x) noexcept;
    void set_y(const double y) noexcept;
    void set_z(const double z) noexcept;

    bool operator==(const Point &point) const noexcept;
    bool is_equal(const Point &point) const noexcept;

    Point operator+(const Point &point) const;
    Point add(const Point &point) const;
    Point operator-(const Point &point) const;
    Point sub(const Point &point) const;

    Point operator-() const;
    Point neg() const;

    Matrix<double> transform(const Matrix<double> &matrix);

  private:
    Matrix<double> data{{0, 0, 0, 1}};
};*/

#endif
