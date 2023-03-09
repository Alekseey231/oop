#ifndef POINT_H
#define POINT_H

#include <errors.h>
#include <files.h>
#include <fstream>

struct point_t
{
    double x;
    double y;
    double z;
};

errors_t input_one_vertice(point_t &point, file_t &file);

#endif // POINT_H
