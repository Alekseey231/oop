#include <draw.h>

static errors_t draw_line(const point_t &start, const point_t &end, const view_t &view);
static errors_t get_edge_points(line_t &line, const edge_t &edge, const point_t *all_points);
errors_t draw_all_edges(const edges_t &edges, const vertices_t &vertices, const view_t &view);

//не нужно ли поменять порядок фигуры и вида
errors_t draw_figure(const figure_t &figure, view_t &view)
{
    errors_t rc = ERR_OK;
    if (!is_scene_init(view))
    {
        return ERR_NOT_INIT_SCENE;
    }
    if (!is_figure_init(figure.all_vertice, figure.all_edge))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    rc = clear_scene(view);
    if (rc == ERR_OK)
    {
        rc = draw_all_edges(figure.all_edge, figure.all_vertice, view);
    }
    return rc;
}

int is_scene_init(const view_t &view)
{
    return view.scene != nullptr;
}

errors_t draw_all_edges(const edges_t &edges, const vertices_t &vertices, const view_t &view)
{
    errors_t rc = ERR_OK;
    if (!is_scene_init(view))
    {
        rc = ERR_NOT_INIT_SCENE;
    }
    if (!is_edges_init(edges.data) || !is_vertices_init(vertices.data))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    line_t line;
    for (size_t i = 0; rc == ERR_OK && i < edges.count; ++i)
    {
        rc = get_edge_points(line, edges.data[i], vertices.data);
        if (rc == ERR_OK)
        {
            rc = draw_line(line.start, line.end, view);
        }
    }
    return rc;
}

static errors_t get_edge_points(line_t &line, const edge_t &edge, const point_t *all_points)
{
    if (!is_vertices_init(all_points))
    {
        return ERR_NOT_INIT_VERTICES;
    }

    line.start = all_points[edge.index_vertice_start];
    line.end = all_points[edge.index_vertice_end];

    return ERR_OK;
}

static errors_t draw_line(const point_t &start, const point_t &end, const view_t &view)
{
    if (!is_scene_init(view))
    {
        return ERR_NOT_INIT_SCENE;
    }

    view.scene->addLine(start.x, start.y, end.x, end.y);
    return ERR_OK;
}

errors_t clear_scene(view_t &view)
{
    if (!is_scene_init(view))
        return ERR_NOT_INIT_SCENE;

    view.scene->clear();
    return ERR_OK;
}
