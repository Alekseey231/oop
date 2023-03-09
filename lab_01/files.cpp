#include <errors.h>
#include <files.h>
#include <point.h>

int is_file_open(file_t &file)
{
    return file.in.is_open();
}

int is_input_success(file_t &file)
{
    return file.in.good();
}

errors_t open_file(file_t &file, file_name_t &filename)
{
    file.in.open(filename.name);
    if (is_file_open(file))
    {
        return ERR_OK;
    }
    return ERR_OPEN_FILE;
}

void close_file(file_t &file)
{
    file.in.close();
}

errors_t read_unsigned(size_t &size, file_t &file)
{
    errors_t rc = ERR_OK;

    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    file.in >> size;

    if (!is_input_success(file))
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}

/*errors_t read_double(double &value, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    file.in >> value;

    if (!is_input_success(file))
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}*/

errors_t read_coordinates(double &x_coord, double &y_coord, double &z_coord, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    file.in >> x_coord >> y_coord >> z_coord;

    if (!is_input_success(file))
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}

/*errors_t read_point(point_t &point, file_t &file)
{
    errors_t rc = ERR_OK;
    if (!is_file_open(file))
    {
        return ERR_OPEN_FILE;
    }

    file.in >> point.x >> point.y >> point.z;

    if (!is_input_success(file))
    {
        rc = ERR_GET_VALUE;
    }
    return rc;
}
*/
