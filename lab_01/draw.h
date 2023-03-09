#ifndef DRAW_H
#define DRAW_H

#include <errors.h>
#include <figure.h>
#include <task.h>

struct line_t
{
    point_t start;
    point_t end;
};

errors_t draw_figure(const figure_t &figure, view_t &view);
int is_scene_init(const view_t &view);
errors_t draw_all_edges(const edges_t &edges, const vertices_t &vertices, const view_t &view);
errors_t clear_scene(view_t &view);

#endif // DRAW_H
