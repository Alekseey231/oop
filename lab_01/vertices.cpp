#include <QDebug>
#include <cmath>
#include <cstring>
#include <vertices.h>

static errors_t input_count_vertices(size_t &count, file_t &file);
static errors_t input_vertices(vertices_t &vertices, file_t &file);
static errors_t preprocess_input_vertices(vertices_t &vertices, file_t &file);

void init_vertices(vertices_t &vertices)
{
    vertices.count = 0;
    vertices.data = nullptr;
}

/*int is_vertices_init(const vertices_t &vertices)
{
    return vertices.data != nullptr;
}*/

int is_vertices_init(const point_t *points)
{
    return points != nullptr;
}

// out in
errors_t input_all_vertices(vertices_t &vertices, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = preprocess_input_vertices(vertices, file);
    if (rc == ERR_OK)
    {
        rc = input_vertices(vertices, file);
        if (rc != ERR_OK)
        {
            free_vertices(vertices);
        }
    }
    return rc;
}

static errors_t preprocess_input_vertices(vertices_t &vertices, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = input_count_vertices(vertices.count, file);
    if (rc == ERR_OK)
    {
        vertices.data = allocate_vertices(vertices.count);
        if (vertices.data == nullptr)
        {
            rc = ERR_ALLOCATE_MEM;
        }
    }

    return rc;
}

point_t *allocate_vertices(size_t count)
{
    point_t *data = (point_t *)calloc(count, sizeof(point_t));
    return data;
}

void free_vertices(vertices_t &vertices)
{
    free(vertices.data);
    vertices.data = nullptr;
}

static errors_t input_count_vertices(size_t &count, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = read_unsigned(count, file);

    if (rc == ERR_OK)
    {
        if (count < 2)
        {
            rc = ERR_INCORRECT_VALUE_VERTICES;
        }
    }
    return rc;
}

static errors_t input_vertices(vertices_t &vertices, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }
    if (!is_vertices_init(vertices.data))
    {
        return ERR_NOT_INIT_VERTICES;
    }

    for (size_t i = 0; i < vertices.count && rc == ERR_OK; ++i)
    {
        rc = input_one_vertice(vertices.data[i], file);
    }

    return rc;
}

errors_t transform_all_vertices(vertices_t &vertices, const transformation_t &param_transform,
                                void (*transform)(point_t &, const transformation_t &))
{
    errors_t rc = ERR_OK;
    if (!is_vertices_init(vertices.data))
    {
        return ERR_NOT_INIT_FIGURE;
    }

    for (size_t i = 0; i < vertices.count; ++i)
    {
        transform(vertices.data[i], param_transform);
    }

    return rc;
}
