#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <QGraphicsScene>
#include <errors.h>
#include <point.h>

enum types_task {scale, transform, rotate, read_file, draw};

struct parametr_tranform_t
{
    double dx;
    double dy;
    double dz;
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

#endif // TASK_H
