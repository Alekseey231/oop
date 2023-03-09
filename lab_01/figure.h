#ifndef FIGURE_H
#define FIGURE_H

#include <edges.h>
#include <errors.h>
#include <iostream>
#include <task.h>
#include <vertices.h>

struct figure_t
{
    vertices_t all_vertice;
    edges_t all_edge;
};

figure_t &init_figure();
errors_t load_figure(figure_t &figure, file_name_t &filename);
errors_t input_figure(figure_t &figure, file_t &file);
errors_t check_correct_figure(const figure_t &figure);
int is_figure_init(const vertices_t &vertices, const edges_t &edges);
void delete_figure(figure_t &figure);
errors_t rotate_figure(figure_t &figure, const transformation_parametrs_t &param_transform);
errors_t scale_figure(figure_t &figure, const transformation_parametrs_t &param_transform);
errors_t move_figure(figure_t &figure, const transformation_parametrs_t &param_transform);

errors_t transform_figure(figure_t &figure, const transformation_t &param_transform,
                          void (*transform)(point_t &, const transformation_t &));

#endif // FIGURE_H
