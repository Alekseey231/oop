#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <errors.h>
#include <task.h>
#include <point.h>

struct vertices_t
{
   point_t *data;
   size_t count;
};

struct edge_t
{
    unsigned index_vertice_start;
    unsigned index_vertice_end;
};

struct edges_t
{
    edge_t *data;
    size_t count;
};


struct figure_t
{
    vertices_t all_vertice;
    edges_t all_edge;
    point_t center;
};

void init_figure(figure_t &figure);
errors_t get_figure(file_t &file, figure_t &figure);
errors_t draw_figure(view_t &view, figure_t &figure);
void delete_figure(figure_t &figure);
errors_t clear_scene(view_t &view);
//errors_t move_figure(figure_t &figure, const parametr_tranform_t &transform);
//errors_t rotate_figure(figure_t &figure, const parametr_tranform_t &transform);
//errors_t scale_figure(figure_t &figure, const parametr_tranform_t &transform);

errors_t transform_figure(figure_t &figure, const parametr_tranform_t param_transform,\
                          void (*transform)(point_t&, const parametr_tranform_t&));

#endif // FIGURE_H
