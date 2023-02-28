#ifndef VERTICES_H
#define VERTICES_H

#include <fstream>
#include <figure.h>
#include "errors.h"

errors_t input_all_vertices(std::ifstream &in, vertices_t &vertices);
errors_t input_vertices(std::ifstream &in,  vertices_t &vertices);
errors_t input_count_vertices(std::ifstream &in, size_t &count);
void allocate_vertices(vertices_t &vertices);
void init_vertices(vertices_t &vertices);
void free_vertices(vertices_t &vertices);
errors_t input_vertice(std::ifstream &in, point_t &point);
int is_vertices_init(const vertices_t &vertices);
void move_point(point_t &point, const parametr_tranform_t &transform);
errors_t move_all_vertices(vertices_t &vertices, const parametr_tranform_t &transform);
void rotate_point(point_t &point, const point_t &center, const parametr_tranform_t &transform);
errors_t rotate_all_vertices(vertices_t &vertices, const point_t &center, const parametr_tranform_t &transform);
void scale_point(point_t &point, const point_t &center, const parametr_tranform_t &transform);
errors_t scale_all_vertices(vertices_t &vertices, const point_t &center, const parametr_tranform_t &transform);

#endif // VERTICES_H
