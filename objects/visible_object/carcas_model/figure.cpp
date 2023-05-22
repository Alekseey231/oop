#include "figure.h"

Figure::Figure(std::vector<Point> &points, std::vector<Edge> &edges) : all_points(points), all_edges(edges) {}

const std::vector<Point> &Figure::get_points() const
{
    return this->all_points;
}
const std::vector<Edge> &Figure::get_edges() const
{
    return this->all_edges;
}

void Figure::addPoint(const Point &point)
{
    this->all_points.push_back(point);
}

void Figure::addEdge(const Edge &edge)
{
    this->all_edges.push_back(edge);
}