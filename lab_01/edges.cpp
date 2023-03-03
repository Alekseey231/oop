#include <cstring>
#include <edges.h>
#include <errors.h>
#include <fstream>

static errors_t input_count_edges(std::ifstream &in, size_t &count);
static errors_t input_edges(std::ifstream &in, edges_t &edges);
static errors_t input_edge(std::ifstream &in, edge_t &edge);

static void draw_edge(const edge_t &edge, const vertices_t &vertices, const view_t &view);

static errors_t check_index_edge(const size_t count_vertices, const edge_t &edge);
static errors_t check_duplicate_edge(const edges_t &edges, const edge_t &edge);

static int compare_edges(const edge_t &first_edge, const edge_t &second_edge);

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
    else if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
    }

    if (rc == ERR_OK)
    {
        rc = input_count_edges(in, edges.count);
        if (rc == ERR_OK)
        {
            rc = allocate_edges(edges);
            if (rc == ERR_OK)
            {
                rc = input_edges(in, edges);
            }
            if (rc != ERR_OK)
            {
                free_edges(edges);
            }
        }
    }
    return rc;
}

static errors_t input_count_edges(std::ifstream &in, size_t &count)
{
    errors_t rc = ERR_OK;
    if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
        return rc;
    }

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

errors_t allocate_edges(edges_t &edges)
{
    errors_t rc = ERR_OK;
    edges.data = (edge_t *)malloc(sizeof(edge_t) * edges.count);
    if (edges.data == NULL)
    {
        rc = ERR_ALLOCATE_MEM;
    }
    return rc;
}

void free_edges(edges_t &edges)
{
    free(edges.data);
    edges.data = nullptr;
}

static errors_t input_edges(std::ifstream &in, edges_t &edges)
{
    errors_t rc = ERR_OK;
    if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
    }
    for (size_t i = 0; i < edges.count && rc == ERR_OK; ++i)
    {
        rc = input_edge(in, edges.data[i]);
    }
    return rc;
}

static errors_t input_edge(std::ifstream &in, edge_t &edge)
{
    errors_t rc = ERR_OK;
    if (!in.is_open())
    {
        rc = ERR_OPEN_FILE;
        return rc;
    }
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

errors_t check_correct_edges(const edges_t &edges, const vertices_t &vertices)
{
    errors_t rc = ERR_OK;
    if (!is_edges_init(edges))
    {
        rc = ERR_NOT_INIT_EDGES;
    }

    for (size_t i = 0; i < edges.count && rc == ERR_OK; ++i)
    {
        rc = check_index_edge(vertices.count, edges.data[i]);
        if (rc == ERR_OK)
        {
            rc = check_duplicate_edge(edges, edges.data[i]);
        }
    }
    return rc;
}

static errors_t check_index_edge(const size_t count_vertices, const edge_t &edge)
{
    errors_t rc = ERR_OK;
    if ((edge.index_vertice_end > (count_vertices - 1)) || (edge.index_vertice_start > (count_vertices - 1)))
    {
        rc = ERR_INDEX_EDGE_TOO_LARGE;
    }
    return rc;
}

static errors_t check_duplicate_edge(const edges_t &edges, const edge_t &edge)
{
    errors_t rc = ERR_OK;

    if (!is_edges_init(edges))
    {
        rc = ERR_NOT_INIT_EDGES;
    }
    unsigned int count_replay = 0;
    for (size_t i = 0; i < edges.count && rc == ERR_OK; ++i)
    {
        if (compare_edges(edge, edges.data[i]))
        {
            ++count_replay;
        }
        if (count_replay == 2)
        {
            rc = ERR_DUBLICATE_EDGE;
        }
    }
    return rc;
}

static int compare_edges(const edge_t &first_edge, const edge_t &second_edge)
{
    return (first_edge.index_vertice_end == second_edge.index_vertice_end) &&
           (first_edge.index_vertice_start == second_edge.index_vertice_start);
}

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
