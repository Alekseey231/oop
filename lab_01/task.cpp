#include "task.h"
#include "draw.h"
#include "error.h"
#include "figure.h"
#include "vertices.h"

static void set_defoult_transformation(transformation_parametrs_t &transformation);
static void set_defoult_transform(transformation_t &transform);
static void set_defoult_view(view_t &view);

errors_t process_event(task_t &task)
{
    static figure_t figure = init_figure();
    errors_t rc = ERR_OK;
    switch (task.type)
    {
    case READ_FILE:
        rc = load_figure(figure, task.file);
        break;
    case DRAW:
        rc = draw_figure(figure, task.view);
        break;
    case TRANSFORM:
        rc = move_figure(figure, task.transformation_param);
        break;
    case ROTATE:
        rc = rotate_figure(figure, task.transformation_param);
        break;
    case SCALE:
        rc = scale_figure(figure, task.transformation_param);
        break;
    case QUIT:
        delete_figure(figure);
        break;
    default:
        rc = ERR_INCORRECT_TASK_TYPE;
        break;
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
    set_defoult_transform(transformation.center);
}

static void set_defoult_transform(transformation_t &transform)
{
    transform.dx = transform.dy = transform.dz = 0;
}

static void set_defoult_view(view_t &view)
{
    view.scene = nullptr;
}
