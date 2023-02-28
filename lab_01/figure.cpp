#include "figure.h"
#include "task.h"
#include "errors.h"
#include <vertices.h>
#include <fstream>
#include <edges.h>
#include <QDebug>

void init_figure(figure_t &figure)
{
    init_edges(figure.all_edge);
    init_vertices(figure.all_vertice);
}

//TODO добавить провреки на nullptr file и что figure пуста
//возможно инит надо будет перенести
errors_t get_figure(file_t &file, figure_t &figure)
{
    errors_t rc = ERR_OK;
    std::ifstream in(file.path_to_file);
    init_figure(figure);
    if(in.is_open())
    {
        rc = input_all_vertices(in, figure.all_vertice);
        if(rc == ERR_OK)
        {
            rc = input_all_edges(in, figure.all_edge);
            if(rc != ERR_OK)
            {
                free_vertices(figure.all_vertice);
            }
        }
    }
    else
    {
        rc = ERR_OPEN_FILE;
    }

    return rc;
}

errors_t move_figure(figure_t &figure, const parametr_tranform_t &transform)
{
    errors_t rc = ERR_OK;
    if(is_edges_init(figure.all_edge) && is_vertices_init(figure.all_vertice))
    {
        rc = move_all_vertices(figure.all_vertice, transform);
    }
    else
    {
        rc = ERR_NOT_INIT_FIGURE;
    }
    return rc;
}

errors_t rotate_figure(figure_t &figure, const parametr_tranform_t &transform)
{
    errors_t rc = ERR_OK;
    if(is_edges_init(figure.all_edge) && is_vertices_init(figure.all_vertice))
    {
        rc = rotate_all_vertices(figure.all_vertice, figure.center, transform);
    }
    else
    {
       rc = ERR_NOT_INIT_FIGURE;
    }
    return rc;
}

errors_t scale_figure(figure_t &figure, const parametr_tranform_t &transform)
{
    errors_t rc = ERR_OK;
    if(is_edges_init(figure.all_edge) && is_vertices_init(figure.all_vertice))
    {
        rc = scale_all_vertices(figure.all_vertice, figure.center, transform);
    }
    else
    {
       rc = ERR_NOT_INIT_FIGURE;
    }
    return rc;
}



// Нужна ли тут проверка инициализации полей?
errors_t draw_figure(view_t &view, figure_t &figure)
{
    errors_t rc = ERR_OK;
    if(is_scene_init(view) == 0)
    {
        rc = ERR_NOT_INIT_SCENE;
    }
    if(rc == ERR_OK)
    {
        rc = clear_scene(view);
    }

    if(rc == ERR_OK)
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
    if(is_scene_init(view) == 0)
    {
        rc = ERR_NOT_INIT_SCENE;
    }
    else
    {
        view.scene->clear();
    }
    return rc;
}
