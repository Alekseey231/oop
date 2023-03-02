#include "task.h"
#include "error.h"
#include "figure.h"
#include "vertices.h"
#include <QDebug>

errors_t process_event(task_t &task)
{
    static figure_t figure = init_figure();
    errors_t rc = ERR_OK;
    switch (task.type)
    {
    case READ_FILE:
        delete_figure(figure);
        rc = input_figure(task.file, figure);
        break;
    case DRAW:
        rc = draw_figure(task.view, figure);
        break;
    case TRANSFORM:
        rc = transform_figure(figure, task.transform, move_point);
        break;
    case ROTATE:
        rc = transform_figure(figure, task.transform, rotate_point);
        break;
    case SCALE:
        rc = transform_figure(figure, task.transform, scale_point);
        break;
    case QUIT:
        delete_figure(figure);
    }
    if (task.type != QUIT)
    {
        task.view.scene->addEllipse(0, 0, 1, 1);
    }
    return rc;
}

void init_task(task_t &task)
{
    task.transform.center.x = task.transform.center.y = task.transform.center.z = 0;
    task.transform.transform.dx = task.transform.transform.dy = task.transform.transform.dz = 0;
    task.view.scene = nullptr;
}
