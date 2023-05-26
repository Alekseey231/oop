#include "CarcasModelFileSource.h"

void CarcasModelFileSource::read_point(std::stringstream &ss)
{
    Point point{0, 0, 0, 1};
    ss >> point[0] >> point[1] >> point[2];
    if (ss.fail())
        // throw FileError(__FILE__, __LINE__, "Could not read vertex");
        this->points.push_back(point);
}

void CarcasModelFileSource::read_edge(std::stringstream &ss)
{
    Edge edge{};
    std::size_t first, second;
    ss >> first >> second;
    if (ss.fail())
        // throw FileError(__FILE__, __LINE__, "Could not read line");
        edge.set_start(first);
    edge.set_end(second);
    this->edges.push_back(edge);
}
