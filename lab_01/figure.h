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
errors_t input_figure(file_t &file, figure_t &figure);
errors_t draw_figure(view_t &view, const figure_t &figure);
void delete_figure(figure_t &figure);
errors_t clear_scene(view_t &view);
errors_t transform_figure(figure_t &figure, const parametr_tranform_t &param_transform,
                          void (*transform)(point_t &, const point_t &, const transformation_t &));

#endif // FIGURE_H
