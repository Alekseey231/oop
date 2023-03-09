#include <cmath>
#include <figure.h>
#include <point.h>

static void rotate_point_z(point_t &point, const double angle);
static void rotate_point_y(point_t &point, const double angle);
static void rotate_point_x(point_t &point, const double angle);

static double scale_coordinate(double point, double scale_ratio);

errors_t input_one_vertice(point_t &point, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = read_coordinates(point.x, point.y, point.z, file);

    return rc;
}

void move_point(point_t &point, const transformation_t &transform)
{
    point.x += transform.dx;
    point.y += transform.dy;
    point.z += transform.dz;
}

static double to_radians(const double &angle)
{
    return angle * M_PI / 180;
}

//возможно угол стоит посчитать на верхнем уровне, и просто передавать вниз, чтобы сократить объем повторных вычислений
void rotate_point(point_t &point, const transformation_t &transform)
{
    rotate_point_x(point, transform.dx);
    rotate_point_y(point, transform.dy);
    rotate_point_z(point, transform.dz);
}

static void rotate_point_x(point_t &point, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_y = point.y;

    point.y = point.y * cos(rad_angle) - point.z * sin(rad_angle);
    point.z = saved_y * sin(rad_angle) + point.z * cos(rad_angle);
}

static void rotate_point_y(point_t &point, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_x = point.x;

    point.x = point.x * cos(rad_angle) - point.z * sin(rad_angle);
    point.z = saved_x * sin(rad_angle) + point.z * cos(rad_angle);
}

static void rotate_point_z(point_t &point, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_x = point.x;

    point.x = point.x * cos(rad_angle) - point.y * sin(rad_angle);
    point.y = saved_x * sin(rad_angle) + point.y * cos(rad_angle);
}

void scale_point(point_t &point, const transformation_t &transform)
{
    point.x = scale_coordinate(point.x, transform.dx);
    point.y = scale_coordinate(point.y, transform.dy);
    point.z = scale_coordinate(point.z, transform.dz);
}

static double scale_coordinate(double point, double scale_ratio)
{
    if (scale_ratio != 0)
    {
        return point * scale_ratio;
    }
    return point;
}
