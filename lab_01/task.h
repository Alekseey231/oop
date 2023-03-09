#ifndef TASK_H
#define TASK_H

#include "files.h"
#include <QGraphicsScene>
#include <errors.h>
#include <fstream>
#include <iostream>
#include <point.h>

enum types_task
{
    SCALE,
    TRANSFORM,
    ROTATE,
    READ_FILE,
    DRAW,
    QUIT
};

struct transformation_t
{
    double dx;
    double dy;
    double dz;
};

struct transformation_parametrs_t
{
    transformation_t transform;
    transformation_t center;
};

struct view_t
{
    QGraphicsScene *scene;
};

struct task_t
{
    enum types_task type;
    file_name_t file;
    view_t view;
    transformation_parametrs_t transformation_param;
};

errors_t process_event(task_t &task);
void init_task(task_t &task);

#endif // TASK_H
