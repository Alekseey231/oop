#include "FileCarcasModelLoader.h"
#include "../exceptions/LoaderExceptions.h"
#include "../objects/visible_object/carcas_model/figure.h"
#include <ctime>

FileCarcasModelLoader::FileCarcasModelLoader() : _file(std::make_shared<std::ifstream>())
{
}

FileCarcasModelLoader::FileCarcasModelLoader(std::shared_ptr<std::ifstream> &file) : _file(file)
{
}

void FileCarcasModelLoader::open(const std::string &fileName)
{
    time_t cur_time = time(NULL);
    if (!_file)
    {
        throw ErrorLoaderFileOpen(typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _file->open(fileName);

    if (!_file->is_open())
    {
        throw ErrorLoaderFileOpen(typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void FileCarcasModelLoader::close()
{
    time_t cur_time = time(NULL);
    if (!_file)
    {
        throw ErrorLoaderFileClose(typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _file->close();
}

std::size_t FileCarcasModelLoader::loadCount()
{
    int count;

    *_file >> count;

    return count;
}

Point FileCarcasModelLoader::loadPoint()
{
    double x, y, z;

    *_file >> x >> y >> z;

    return Point(x, y, z, 1);
}

std::vector<Point> FileCarcasModelLoader::loadPoints()
{
    std::vector<Point> vertexes;
    time_t cur_time = time(NULL);

    int vertexNum;
    *_file >> vertexNum;

    if (vertexNum <= 0)
    {
        ErrorLoaderFileCountPoints(typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    double x, y, z;

    for (int i = 0; i < vertexNum; i++)
    {
        *_file >> x >> y >> z;
        vertexes.push_back(Point(x, y, z, 1));
    }

    return vertexes;
}

std::vector<Edge> FileCarcasModelLoader::loadEdges(int &vertexNum)
{
    std::vector<Edge> links;
    time_t cur_time = time(NULL);

    int linksNum;
    *_file >> linksNum;

    if (linksNum <= 0)
    {
        ErrorLoaderFileCountEdges(typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    int vertex1Index, vertex2Index;

    for (int i = 0; i < linksNum; i++)
    {
        *_file >> vertex1Index >> vertex2Index;

        if (vertex1Index <= 0 or vertex2Index <= 0 or vertex1Index > vertexNum or vertex2Index > vertexNum)
        {
            throw ErrorLoaderIndexPoints(typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        links.push_back(Edge(vertex1Index, vertex2Index));
    }

    return links;
}
