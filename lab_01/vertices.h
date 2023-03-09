#ifndef VERTICES_H
#define VERTICES_H

#include "errors.h"
#include <fstream>
#include <point.h>
#include <task.h>

struct vertices_t
{
    point_t *data;
    size_t count;
};

errors_t input_all_vertices(vertices_t &vertices, file_t &file);

point_t *allocate_vertices(size_t count);
void free_vertices(vertices_t &vertices);

void init_vertices(vertices_t &vertices);
int is_vertices_init(const point_t *points);
// int is_vertices_init(const vertices_t &vertices);

void move_point(point_t &point, const transformation_t &transform);
void rotate_point(point_t &point, const transformation_t &transform);
void scale_point(point_t &point, const transformation_t &transform);

errors_t transform_all_vertices(vertices_t &vertices, const transformation_t &param_transform,
                                void (*transform)(point_t &, const transformation_t &));
#endif // VERTICES_H
