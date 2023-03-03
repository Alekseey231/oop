#include "task.h"
#include "error.h"
#include "figure.h"
#include "vertices.h"

static void set_defoult_transformation(transformation_parametrs_t &transformation);
static void set_defoult_transform(transformation_t &transform);
static void set_defoult_center(point_t &center);
static void set_defoult_view(view_t &view);

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
    return rc;
}

void init_task(task_t &task)
{
    set_defoult_transformation(task.transformation_param);
    set_defoult_view(task.view);
}

static void set_defoult_transformation(transformation_parametrs_t &transformation)
{
    set_defoult_transform(transformation.transform);
    set_defoult_center(transformation.center);
}

static void set_defoult_center(point_t &center)
{
    center.x = center.y = center.z = 0;
}

static void set_defoult_transform(transformation_t &transform)
{
    transform.dx = transform.dy = transform.dz = 0;
}

static void set_defoult_view(view_t &view)
{
    view.scene = nullptr;
}
