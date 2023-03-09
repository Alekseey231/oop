#ifndef EDGES_H
#define EDGES_H

#include <errors.h>
#include <fstream>
#include <task.h>
#include <vertices.h>

struct edge_t
{
    size_t index_vertice_start;
    size_t index_vertice_end;
};

struct edges_t
{
    edge_t *data;
    size_t count;
};

errors_t input_all_edges(edges_t &edges, file_t &file);
void init_edges(edges_t &edges);

// int is_edges_init(const edges_t &edges);
int is_edges_init(const edge_t *edges);
errors_t check_correct_edges(const edges_t &edges, const vertices_t &vertices);

edge_t *allocate_edges(size_t count);
void free_edges(edges_t &edges);

errors_t draw_all_edges(const edges_t &edges, const vertices_t &vertices, const view_t &view);
int is_scene_init(const view_t &view);

#endif // EDGES_H
