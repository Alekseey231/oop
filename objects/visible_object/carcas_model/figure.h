#ifndef FIGURE_H
#define FIGURE_H

#include <vector>

#include "../../../math/glm_wrapped.h"
#include "edge.h"
//#include "point.h"

typedef Vector4 Point;

class Figure
{
  public:
    Figure() = default;
    Figure(std::vector<Point> &points, std::vector<Edge> &edges);

    ~Figure() = default;

    const std::vector<Point> &get_points() const;
    const std::vector<Edge> &get_edges() const;

    void addPoint(const Point &point);
    void addEdge(const Edge &edge);

  private:
    std::vector<Point> all_points;
    std::vector<Edge> all_edges;
};

#endif
