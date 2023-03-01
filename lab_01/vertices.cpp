#include <vertices.h>
#include <QDebug>
#include <cmath>

void rotate_point_z(point_t &point, const point_t &center, const double angle);
void rotate_point_y(point_t &point, const point_t &center, const double angle);
void rotate_point_x(point_t &point, const point_t &center, const double angle);
static double scale_coordinate(double point, double center, double scale_ratio);
void scale_point_coord(point_t &point, const point_t &center, const parametr_tranform_t &transform);

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
    if(is_vertices_init(vertices))
    {
        rc = ERR_NOT_INIT_FIGURE;
    }

    if(rc == ERR_OK)
    {
        rc = input_count_vertices(in, vertices.count);
        if(rc == ERR_OK)
        {
            allocate_vertices(vertices);
            rc = input_vertices(in, vertices);
            if(rc != ERR_OK)
            {
                free_vertices(vertices);
            }
        }
    }
    return rc;
}

void allocate_vertices(vertices_t &vertices)
{
    vertices.data = new point_t[vertices.count];
}

void free_vertices(vertices_t &vertices)
{
    delete [] vertices.data;
}

errors_t input_count_vertices(std::ifstream &in, size_t &count)
{
    errors_t rc = ERR_OK;
    in >> count;
    if(in.good())
    {
        if(count < 2)
        {
            rc = ERR_INCORRECT_VALUE;
        }
    }
    else
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}

errors_t input_vertices(std::ifstream &in,  vertices_t &vertices)
{
    errors_t rc = ERR_OK;
    for(size_t i = 0; i < vertices.count && rc == ERR_OK; ++i)
    {
        rc = input_vertice(in, vertices.data[i]);
    }
    return rc;
}

errors_t input_vertice(std::ifstream &in, point_t &point)
{
    errors_t rc = ERR_OK;
    in >> point.x;
    in >> point.y;
    in >> point.z;
    if(in.good() == 0)
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}

errors_t transform_all_vertices(vertices_t &vertices, const parametr_tranform_t &param_transform,
                                void (*transform)(point_t&, const parametr_tranform_t&))
{
    errors_t rc = ERR_OK;
    if(is_vertices_init(vertices) == 0)
    {
        rc = ERR_NOT_INIT_FIGURE;
    }
    else
    {
        for(size_t i = 0; i < vertices.count; ++i)
        {
            transform(vertices.data[i], param_transform);
        }
    }
    return rc;
}


void move_point(point_t &point, const parametr_tranform_t &transform)
{
    point.x += transform.dx;
    point.y += transform.dy;
    point.z += transform.dz;
}

double to_radians(const double &angle)
{
    return angle * M_PI / 180;
}

void rotate_point(point_t &point, const parametr_tranform_t &transform)
{
    rotate_point_x(point, transform.center, transform.dx);
    rotate_point_y(point, transform.center, transform.dy);
    rotate_point_z(point, transform.center, transform.dz);
}

void rotate_point_x(point_t &point, const point_t &center, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_y = point.y;

    point.x = point.x;
    point.y = (point.y - center.y) * cos(rad_angle) - (point.z - center.z) * sin(rad_angle) + center.y;
    point.z = (saved_y - center.y) * sin(rad_angle) + (point.z - center.z) * cos(rad_angle) + center.z;
}

void rotate_point_y(point_t &point, const point_t &center, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_x = point.x;

    point.y = point.y;
    point.x = (point.x - center.x) * cos(rad_angle) - (point.z - center.z) * sin(rad_angle) + center.x;
    point.z = (saved_x - center.x) * sin(rad_angle) + (point.z - center.z) * cos(rad_angle) + center.z;
}

void rotate_point_z(point_t &point, const point_t &center, const double angle)
{
    double rad_angle = to_radians(angle);
    double saved_x = point.x;

    point.z = point.z;
    point.x = (point.x - center.x) * cos(rad_angle) - (point.y - center.y) * sin(rad_angle) + center.x;
    point.y = (saved_x - center.x) * sin(rad_angle) + (point.y - center.y) * cos(rad_angle) + center.y;
}


void scale_point(point_t &point, const parametr_tranform_t &transform)
{
    scale_point_coord(point, transform.center, transform);
}

void scale_point_coord(point_t &point, const point_t &center, const parametr_tranform_t &transform)
{
    point.x = scale_coordinate(point.x, center.x, transform.dx);
    point.y = scale_coordinate(point.y, center.y, transform.dy);
    point.z = scale_coordinate(point.z, center.z, transform.dz);
}

static double scale_coordinate(double point, double center, double scale_ratio)
{
    if(scale_ratio != 0)
    {
        return (point - center) * scale_ratio + center;
    }
    return point;
}









