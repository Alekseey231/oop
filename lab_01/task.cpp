#include "task.h"
#include "error.h"
#include "figure.h"
#include <QDebug>
#include "vertices.h"

errors_t process_event(task_t &task)
{
    static figure_t figure;
    errors_t rc = ERR_OK;
    if(task.type == read_file)
    {
        //добавить очистку памяти
        rc = get_figure(task.file, figure);
    }
    else if(task.type == draw)
    {
        rc = draw_figure(task.view, figure);
    }
    else if(task.type == transform)
    {
        task.transform.center.x = task.transform.center.y = task.transform.center.z = 0;
        rc= transform_figure(figure, task.transform, move_point);
    }
    else if(task.type == rotate)
    {
        task.transform.center.x = task.transform.center.y = task.transform.center.z = 0;
        rc= transform_figure(figure, task.transform, rotate_point);
    }
    else if(task.type == scale)
    {
        task.transform.center.x = task.transform.center.y = task.transform.center.z = 0;
        rc= transform_figure(figure, task.transform, scale_point);
    }
    task.view.scene->addEllipse(0,0,1,1);
    return rc;
}
