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
        rc = transform_figure(figure, task.transformation_param, move_point);
        break;
    case ROTATE:
        rc = transform_figure(figure, task.transformation_param, rotate_point);
        break;
    case SCALE:
        rc = transform_figure(figure, task.transformation_param, scale_point);
        break;
    case QUIT:
        delete_figure(figure);
    }
    task.view.scene->addEllipse(0, 0, 1, 1);
    return rc;
}

void init_task(task_t &task)
{
    task.transformation_param.center.x = task.transformation_param.center.y = task.transformation_param.center.z = 0;
    task.transformation_param.center.x = task.transformation_param.center.y = task.transformation_param.center.z = 0;
    task.transformation_param.transform.dx = task.transformation_param.transform.dy =
        task.transformation_param.transform.dz = 0;
    task.view.scene = nullptr;
}
