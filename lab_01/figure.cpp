#include "figure.h"
#include "errors.h"
#include "files.h"
#include "task.h"
#include <QDebug>
#include <fstream>

transformation_t &preprocess_center(transformation_t &center);
void copy_figure(figure_t &dst, figure_t &src);

figure_t &init_figure()
{
    static figure_t figure;
    init_edges(figure.all_edge);
    init_vertices(figure.all_vertice);
    return figure;
}

int is_figure_init(const vertices_t &vertices, const edges_t &edges)
{
    return is_vertices_init(vertices.data) && is_edges_init(edges.data);
}

// out-param, var-param, input-param
errors_t load_figure(figure_t &figure, file_name_t &filename)
{
    errors_t rc = ERR_OK;
    file_t file;
    rc = open_file(file, filename);
    if (rc == ERR_OK)
    {
        figure_t temporary_figure;

        rc = input_figure(temporary_figure, file);
        close_file(file);

        if (rc == ERR_OK)
        {
            rc = check_correct_figure(temporary_figure);
            if (rc == ERR_OK)
            {
                delete_figure(figure);
                copy_figure(figure, temporary_figure);
            }
            else
            {
                delete_figure(temporary_figure);
            }
        }
    }
    return rc;
}

void copy_figure(figure_t &dst, figure_t &src)
{
    dst = src;
}

// out in
errors_t input_figure(figure_t &figure, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = input_all_vertices(figure.all_vertice, file);

    if (rc == ERR_OK)
    {
        rc = input_all_edges(figure.all_edge, file);
        if (rc != ERR_OK)
        {
            free_vertices(figure.all_vertice);
        }
    }
    return rc;
}

errors_t check_correct_figure(const figure_t &figure)
{
    if (!is_figure_init(figure.all_vertice, figure.all_edge))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    return check_correct_edges(figure.all_edge, figure.all_vertice);
}

errors_t move_figure(figure_t &figure, const transformation_parametrs_t &param_transform)
{
    if (!is_figure_init(figure.all_vertice, figure.all_edge))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    return transform_figure(figure, param_transform.transform, move_point);
}

errors_t rotate_figure(figure_t &figure, const transformation_parametrs_t &param_transform)
{
    errors_t rc = ERR_OK;
    if (!is_figure_init(figure.all_vertice, figure.all_edge))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    transformation_t center_transform = param_transform.center;

    rc = transform_figure(figure, preprocess_center(center_transform), move_point);
    if (rc == ERR_OK)
    {
        rc = transform_figure(figure, param_transform.transform, rotate_point);
    }
    if (rc == ERR_OK)
    {
        rc = transform_figure(figure, preprocess_center(center_transform), move_point);
    }
    return rc;
}

errors_t scale_figure(figure_t &figure, const transformation_parametrs_t &param_transform)
{
    errors_t rc = ERR_OK;
    if (!is_figure_init(figure.all_vertice, figure.all_edge))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    transformation_t center_transform = param_transform.center;

    rc = transform_figure(figure, preprocess_center(center_transform), move_point);
    if (rc == ERR_OK)
    {
        rc = transform_figure(figure, param_transform.transform, scale_point);
    }
    if (rc == ERR_OK)
    {
        rc = transform_figure(figure, preprocess_center(center_transform), move_point);
    }
    return rc;
}

errors_t transform_figure(figure_t &figure, const transformation_t &param_transform,
                          void (*transform)(point_t &, const transformation_t &))
{
    if (!is_figure_init(figure.all_vertice, figure.all_edge))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    return transform_all_vertices(figure.all_vertice, param_transform, transform);
}

//вынести в другой файл
transformation_t &preprocess_center(transformation_t &center)
{
    center.dx *= -1;
    center.dy *= -1;
    center.dz *= -1;
    return center;
}

void delete_figure(figure_t &figure)
{
    free_edges(figure.all_edge);
    free_vertices(figure.all_vertice);
}
