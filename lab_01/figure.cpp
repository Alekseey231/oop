#include "figure.h"
#include "errors.h"
#include "task.h"
#include <QDebug>
#include <edges.h>
#include <fstream>
#include <vertices.h>

figure_t &init_figure()
{
    static figure_t figure;
    init_edges(figure.all_edge);
    init_vertices(figure.all_vertice);
    return figure;
}

errors_t input_figure(file_t &file, figure_t &figure)
{
    errors_t rc = ERR_OK;

    if (is_vertices_init(figure.all_vertice) || is_edges_init(figure.all_edge))
    {
        rc = ERR_FIGURE_ALWAYS_INIT;
        return rc;
    }

    std::ifstream in(file.path_to_file);

    if (in.is_open())
    {
        rc = input_all_vertices(in, figure.all_vertice);
        if (rc == ERR_OK)
        {
            rc = input_all_edges(in, figure.all_edge);
            if (rc != ERR_OK)
            {
                free_vertices(figure.all_vertice);
            }
        }
        in.close();

        if (rc == ERR_OK)
        {
            rc = check_correct_figure(figure);
            if (rc != ERR_OK)
            {
                delete_figure(figure);
            }
        }
    }
    else
    {
        rc = ERR_OPEN_FILE;
    }

    return rc;
}

errors_t check_correct_figure(const figure_t &figure)
{
    errors_t rc = ERR_OK;
    if (!is_vertices_init(figure.all_vertice) || !is_edges_init(figure.all_edge))
    {
        rc = ERR_NOT_INIT_FIGURE;
    }
    else
    {
        rc = check_correct_edges(figure.all_edge, figure.all_vertice);
    }
    return rc;
}

errors_t transform_figure(figure_t &figure, const transformation_parametrs_t &param_transform,
                          void (*transform)(point_t &, const point_t &, const transformation_t &))
{
    errors_t rc = ERR_OK;
    if (is_edges_init(figure.all_edge) && is_vertices_init(figure.all_vertice))
    {
        rc = transform_all_vertices(figure.all_vertice, param_transform, transform);
    }
    else
    {
        rc = ERR_NOT_INIT_FIGURE;
    }
    return rc;
}

// Нужна ли тут проверка инициализации полей?
errors_t draw_figure(view_t &view, const figure_t &figure)
{
    errors_t rc = ERR_OK;
    if (is_scene_init(view) == 0)
    {
        rc = ERR_NOT_INIT_SCENE;
    }
    if (rc == ERR_OK)
    {
        rc = clear_scene(view);
    }

    if (rc == ERR_OK)
    {
        rc = draw_all_edges(figure.all_edge, figure.all_vertice, view);
    }
    return rc;
}

void delete_figure(figure_t &figure)
{
    free_edges(figure.all_edge);
    free_vertices(figure.all_vertice);
}

errors_t clear_scene(view_t &view)
{
    errors_t rc = ERR_OK;
    if (is_scene_init(view) == 0)
    {
        rc = ERR_NOT_INIT_SCENE;
    }
    else
    {
        view.scene->clear();
    }
    return rc;
}
