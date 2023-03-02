#ifndef ERRORS_H
#define ERRORS_H

enum errors_t
{
    ERR_OK,
    ERR_OPEN_FILE,
    ERR_GET_VALUE,
    ERR_INCORRECT_VALUE_EDGES,
    ERR_INCORRECT_VALUE_VERTICES,
    ERR_NOT_INIT_FIGURE,
    ERR_NOT_INIT_EDGES,
    ERR_NOT_INIT_VERTICES,
    ERR_NOT_INIT_SCENE,
    ERR_NOT_INIT_FILE,
    ERR_FIGURE_ALWAYS_INIT,
    ERR_ZERO_SCALE_VALUE,
    ERR_INDEX_EDGE_TOO_LARGE,
    ERR_DUBLICATE_EDGE
};
void process_error(errors_t rc);

#endif // ERRORS_H
