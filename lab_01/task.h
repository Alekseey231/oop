#ifndef TASK_H
#define TASK_H

#include <QGraphicsScene>
#include <errors.h>
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

struct parametr_tranform_t
{
    transformation_t transform;
    point_t center;
};

struct file_t
{
    std::string path_to_file;
};

struct view_t
{
    QGraphicsScene *scene;
};

struct task_t
{
    enum types_task type;
    file_t file;
    view_t view;
    parametr_tranform_t transform;
};

errors_t process_event(task_t &task);
void init_task(task_t &task);

#endif // TASK_H
