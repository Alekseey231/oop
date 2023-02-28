#include "task.h"
#include "error.h"
#include "figure.h"
#include <QDebug>

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
        rc = move_figure(figure, task.transform);
    }
    else if(task.type == rotate)
    {
        figure.center.x = figure.center.y = figure.center.z = 0;
        rc= rotate_figure(figure, task.transform);
    }
    else if(task.type == scale)
    {
        figure.center.x = figure.center.y = figure.center.z = 0;
        rc= scale_figure(figure, task.transform);
    }
    task.view.scene->addEllipse(0,0,1,1);
    return rc;
}
