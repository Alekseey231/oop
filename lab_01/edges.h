#ifndef EDGES_H
#define EDGES_H

#include <errors.h>
#include <figure.h>
#include <fstream>

errors_t input_all_edges(std::ifstream &in, edges_t &edges);
errors_t input_count_edges(std::ifstream &in, size_t &count);
void allocate_edges(edges_t &edges);
void free_edges(edges_t &edges);
errors_t input_edges(std::ifstream &in, edges_t &edges);
errors_t input_edge(std::ifstream &in, edge_t &edge);
void init_edges(edges_t &edges);
int is_edges_init(const edges_t &edges);
errors_t draw_all_edges(edges_t &edges, vertices_t &vertices, view_t &view);
void draw_edge(edge_t &edge, vertices_t &vertices, view_t &view);
int is_scene_init(const view_t &view);

#endif // EDGES_H
