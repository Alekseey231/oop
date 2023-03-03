#include <QDebug>
#include <cmath>
#include <cstring>
#include <vertices.h>

static errors_t input_count_vertices(std::ifstream &in, size_t &count);
static errors_t input_vertices(std::ifstream &in, vertices_t &vertices);
static errors_t input_one_vertice(std::ifstream &in, point_t &point);

static void rotate_point_z(point_t &point, const point_t &center, const double angle);
static void rotate_point_y(point_t &point, const point_t &center, const double angle);
static void rotate_point_x(point_t &point, const point_t &center, const double angle);

static double scale_coordinate(double point, double center, double scale_ratio);

void init_vertices(vertices_t &vertices)
{
    vertices.count = 0;
    vertices.data = nullptr;
}

int is_vertices_init(const vertices_t &vertices)
{
    return vertices.data != nullptr;
}

errors_t input_all_vertices(std::ifstream &in, vertices_t &vertices)
{
    errors_t rc = ERR_OK;
    if (is_vertices_init(vertices))
    {
        rc = ERR_FIGURE_ALWAYS_INIT;
    }
    else if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
    }

    if (rc == ERR_OK)
    {
        rc = input_count_vertices(in, vertices.count);
        if (rc == ERR_OK)
        {
            rc = allocate_vertices(vertices);
            if (rc == ERR_OK)
            {
                rc = input_vertices(in, vertices);
            }
            if (rc != ERR_OK)
            {
                free_vertices(vertices);
            }
        }
    }
    return rc;
}

errors_t allocate_vertices(vertices_t &vertices)
{
    errors_t rc = ERR_OK;
    vertices.data = (point_t *)malloc(sizeof(point_t) * vertices.count);
    if (vertices.data == nullptr)
    {
        rc = ERR_ALLOCATE_MEM;
    }
    return rc;
}

void free_vertices(vertices_t &vertices)
{
    free(vertices.data);
    vertices.data = nullptr;
}

static errors_t input_count_vertices(std::ifstream &in, size_t &count)
{
    errors_t rc = ERR_OK;
    if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
        return rc;
    }
    in >> count;
    if (in.good())
    {
        if (count < 2)
        {
            rc = ERR_INCORRECT_VALUE_VERTICES;
        }
    }
    else
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}

static errors_t input_vertices(std::ifstream &in, vertices_t &vertices)
{
    errors_t rc = ERR_OK;
    if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
    }
    for (size_t i = 0; i < vertices.count && rc == ERR_OK; ++i)
    {
        rc = input_one_vertice(in, vertices.data[i]);
    }
    return rc;
}

static errors_t input_one_vertice(std::ifstream &in, point_t &point)
{
    errors_t rc = ERR_OK;
    if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
        return rc;
    }
    in >> point.x;
    in >> point.y;
    in >> point.z;
    if (in.good() == 0)
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}

errors_t transform_all_vertices(vertices_t &vertices, const transformation_parametrs_t &param_transform,
                                void (*transform)(point_t &, const point_t &, const transformation_t &))
{
    errors_t rc = ERR_OK;
    if (is_vertices_init(vertices) == 0)
    {
        rc = ERR_NOT_INIT_FIGURE;
    }
    else
    {
        for (size_t i = 0; i < vertices.count; ++i)
        {
            transform(vertices.data[i], param_transform.center, param_transform.transform);
        }
    }
    return rc;
}

void move_point(point_t &point, const point_t &center, const transformation_t &transform)
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
void rotate_point(point_t &point, const point_t &center, const transformation_t &transform)
{
    rotate_point_x(point, center, transform.dx);
    rotate_point_y(point, center, transform.dy);
    rotate_point_z(point, center, transform.dz);
}

static void rotate_point_x(point_t &point, const point_t &center, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_y = point.y;

    point.y = (point.y - center.y) * cos(rad_angle) - (point.z - center.z) * sin(rad_angle) + center.y;
    point.z = (saved_y - center.y) * sin(rad_angle) + (point.z - center.z) * cos(rad_angle) + center.z;
}

static void rotate_point_y(point_t &point, const point_t &center, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_x = point.x;

    point.x = (point.x - center.x) * cos(rad_angle) - (point.z - center.z) * sin(rad_angle) + center.x;
    point.z = (saved_x - center.x) * sin(rad_angle) + (point.z - center.z) * cos(rad_angle) + center.z;
}

static void rotate_point_z(point_t &point, const point_t &center, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_x = point.x;

    point.x = (point.x - center.x) * cos(rad_angle) - (point.y - center.y) * sin(rad_angle) + center.x;
    point.y = (saved_x - center.x) * sin(rad_angle) + (point.y - center.y) * cos(rad_angle) + center.y;
}

void scale_point(point_t &point, const point_t &center, const transformation_t &transform)
{
    point.x = scale_coordinate(point.x, center.x, transform.dx);
    point.y = scale_coordinate(point.y, center.y, transform.dy);
    point.z = scale_coordinate(point.z, center.z, transform.dz);
}

static double scale_coordinate(double point, double center, double scale_ratio)
{
    if (scale_ratio != 0)
    {
        return (point - center) * scale_ratio + center;
    }
    return point;
}
