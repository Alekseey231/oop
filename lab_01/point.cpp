#include <cmath>
#include <figure.h>
#include <point.h>

static void rotate_point_z(point_t &point, const double angle);
static void rotate_point_y(point_t &point, const double angle);
static void rotate_point_x(point_t &point, const double angle);
static void rotate_point(double &first_coord, double &second_coord, const double angle);

static double scale_coordinate(double point, double scale_ratio);

errors_t input_one_vertice(point_t &point, file_t &file)
{
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    return read_coordinates(point.x, point.y, point.z, file);
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

void rotate_point(point_t &point, const transformation_t &transform)
{
    rotate_point_x(point, transform.dx);
    rotate_point_y(point, transform.dy);
    rotate_point_z(point, transform.dz);
}

static void rotate_point_x(point_t &point, const double angle)
{
    rotate_point(point.y, point.z, angle);
}

static void rotate_point_y(point_t &point, const double angle)
{
    rotate_point(point.x, point.z, angle);
}

static void rotate_point_z(point_t &point, const double angle)
{
    rotate_point(point.x, point.y, angle);
}

static void rotate_point(double &first_coord, double &second_coord, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_first = first_coord;

    first_coord = first_coord * cos(rad_angle) - second_coord * sin(rad_angle);
    second_coord = saved_first * sin(rad_angle) + second_coord * cos(rad_angle);
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
