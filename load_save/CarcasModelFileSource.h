#ifndef CARCASMODELFILESOURCE_H
#define CARCASMODELFILESOURCE_H

#include "./CarcasModelSource.h"
#include <fstream>
#include <sstream>

class CarcasModelFileSource : public CarcasModelSource
{
  public:
    explicit CarcasModelFileSource(const std::string &path);
    std::optional<Edge> next_edge() override;
    std::optional<Point> next_point() override;

  private:
    std::ifstream file;
    std::vector<Point> points;
    std::vector<Edge> edges;
    void read_point(std::stringstream &s);
    void read_edge(std::stringstream &s);
};

#endif // CARCASMODELFILESOURCE_H
