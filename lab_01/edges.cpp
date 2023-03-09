#include <QDebug>
#include <cstring>
#include <edges.h>
#include <errors.h>
#include <files.h>
#include <fstream>

static errors_t preprocess_input_edges(edges_t &edges, file_t &file);
static errors_t input_count_edges(size_t &count, file_t &file);
static errors_t input_edges(edges_t &edges, file_t &file);
static errors_t input_one_edge(edge_t &edge, file_t &file);

static errors_t check_index_edge(const size_t count_vertices, const edge_t &edge);
static errors_t check_duplicate_edge(const edges_t &edges, const size_t index);

static int compare_edges(const edge_t &first_edge, const edge_t &second_edge);

void init_edges(edges_t &edges)
{
    edges.count = 0;
    edges.data = nullptr;
}

int is_edges_init(const edge_t *edges)
{
    return edges != nullptr;
}

errors_t input_all_edges(edges_t &edges, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = preprocess_input_edges(edges, file);
    if (rc == ERR_OK)
    {
        rc = input_edges(edges, file);
        if (rc != ERR_OK)
        {
            free_edges(edges);
        }
    }

    return rc;
}

static errors_t preprocess_input_edges(edges_t &edges, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = input_count_edges(edges.count, file);
    if (rc == ERR_OK)
    {
        edges.data = (edge_t *)allocate_edges(edges.count);
        if (edges.data == nullptr)
        {
            rc = ERR_ALLOCATE_MEM;
        }
    }
    return rc;
}

static errors_t input_count_edges(size_t &count, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = read_unsigned(count, file);
    if (rc == ERR_OK)
    {
        if (count < 1)
        {
            rc = ERR_INCORRECT_VALUE_EDGES;
        }
    }
    return rc;
}

edge_t *allocate_edges(size_t count)
{
    edge_t *data = (edge_t *)calloc(count, sizeof(edge_t));
    return data;
}

void free_edges(edges_t &edges)
{
    free(edges.data);
    edges.data = nullptr;
}

static errors_t input_edges(edges_t &edges, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }
    if (!is_edges_init(edges.data))
    {
        return ERR_NOT_INIT_EDGES;
    }

    for (size_t i = 0; i < edges.count && rc == ERR_OK; ++i)
    {
        rc = input_one_edge(edges.data[i], file);
    }
    return rc;
}

static errors_t input_one_edge(edge_t &edge, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    rc = read_unsigned(edge.index_vertice_start, file);
    if (rc == ERR_OK)
    {
        rc = read_unsigned(edge.index_vertice_end, file);
    }
    return rc;
}

errors_t check_correct_edges(const edges_t &edges, const vertices_t &vertices)
{
    errors_t rc = ERR_OK;
    if (!is_edges_init(edges.data))
    {
        return ERR_NOT_INIT_EDGES;
    }
    if (!is_vertices_init(vertices.data))
    {
        return ERR_NOT_INIT_VERTICES;
    }

    for (size_t i = 0; i < edges.count && rc == ERR_OK; ++i)
    {
        rc = check_index_edge(vertices.count, edges.data[i]);
        if (rc == ERR_OK)
        {
            rc = check_duplicate_edge(edges, i);
        }
    }
    return rc;
}

static errors_t check_index_edge(const size_t count_vertices, const edge_t &edge)
{
    if ((edge.index_vertice_end > (count_vertices - 1)) || (edge.index_vertice_start > (count_vertices - 1)))
    {
        return ERR_INDEX_EDGE_TOO_LARGE;
    }
    return ERR_OK;
}

static errors_t check_duplicate_edge(const edges_t &edges, const size_t index)
{
    errors_t rc = ERR_OK;

    if (!is_edges_init(edges.data))
    {
        rc = ERR_NOT_INIT_EDGES;
    }
    unsigned int count_replay = 0;
    for (size_t i = 0; i < edges.count && rc == ERR_OK; ++i)
    {
        if (compare_edges(edges.data[index], edges.data[i]))
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
