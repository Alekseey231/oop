#ifndef FILES_H
#define FILES_H

#include <errors.h>
#include <fstream>

struct file_t
{
    std::ifstream in;
};

struct file_name_t
{
    std::string name;
};

errors_t open_file(file_t &file, file_name_t &filename);
void close_file(file_t &file);
int is_file_open(file_t &file);
int is_input_success(file_t &file);
errors_t read_coordinates(double &x_coord, double &y_coord, double &z_coord, file_t &file);
// errors_t read_point(point_t &point, file_t &file);
errors_t read_unsigned(size_t &size, file_t &file);

#endif // FILES_H
