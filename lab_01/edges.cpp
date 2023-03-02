#include <QDebug>
#include <edges.h>
#include <errors.h>
#include <figure.h>
#include <fstream>

static errors_t input_count_edges(std::ifstream &in, size_t &count);
static errors_t input_edges(std::ifstream &in, edges_t &edges);
static errors_t input_edge(std::ifstream &in, edge_t &edge);

static void draw_edge(const edge_t &edge, const vertices_t &vertices, const view_t &view);

void init_edges(edges_t &edges)
{
    edges.count = 0;
    edges.data = nullptr;
}

int is_edges_init(const edges_t &edges)
{
    return edges.data != nullptr;
}

errors_t input_all_edges(std::ifstream &in, edges_t &edges)
{
    errors_t rc = ERR_OK;
    if (is_edges_init(edges))
    {
        rc = ERR_FIGURE_ALWAYS_INIT;
    }

    if (rc == ERR_OK)
    {
        rc = input_count_edges(in, edges.count);
        if (rc == ERR_OK)
        {
            allocate_edges(edges);
            rc = input_edges(in, edges);
            if (rc != ERR_OK)
            {
                free_edges(edges);
            }
        }
    }
    return rc;
}

//возможно потом где-то надо проверить, что число ребер хотя бы больше числа вершин
//и что все индексы допустимые
static errors_t input_count_edges(std::ifstream &in, size_t &count)
{
    errors_t rc = ERR_OK;
    in >> count;
    if (in.good())
    {
        if (count <= 1)
        {
            rc = ERR_INCORRECT_VALUE_EDGES;
        }
    }
    else
    {
        rc = ERR_GET_VALUE;
    }

    return rc;
}

//возможно и здесь на init добавить проверку
void allocate_edges(edges_t &edges)
{
    edges.data = new edge_t[edges.count];
}

void free_edges(edges_t &edges)
{
    delete[] edges.data;
    edges.data = nullptr;
}

static errors_t input_edges(std::ifstream &in, edges_t &edges)
{
    errors_t rc = ERR_OK;
    for (size_t i = 0; i < edges.count && rc == ERR_OK; ++i)
    {
        rc = input_edge(in, edges.data[i]);
    }
    return rc;
}

static errors_t input_edge(std::ifstream &in, edge_t &edge)
{
    errors_t rc = ERR_OK;
    in >> edge.index_vertice_start;
    if (in.good())
    {
        in >> edge.index_vertice_end;
    }
    if (in.good() == 0)
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}

//возможно стоит перенести в другой файл
int is_scene_init(const view_t &view)
{
    return view.scene != nullptr;
}

errors_t draw_all_edges(const edges_t &edges, const vertices_t &vertices, const view_t &view)
{
    errors_t rc = ERR_OK;
    if (is_scene_init(view) == 0)
    {
        rc = ERR_NOT_INIT_SCENE;
    }

    for (size_t i = 0; rc == ERR_OK && i < edges.count; ++i)
    {
        draw_edge(edges.data[i], vertices, view);
    }
    return rc;
}

static void draw_edge(const edge_t &edge, const vertices_t &vertices, const view_t &view)
{
    point_t &first_point = vertices.data[edge.index_vertice_start];
    point_t &end_point = vertices.data[edge.index_vertice_end];
    view.scene->addLine(first_point.x, first_point.y, end_point.x, end_point.y);
}
