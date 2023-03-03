#include <QMessageBox>
#include <errors.h>
#include <mainwindow.h>

//добавить ошибки, что фигура не загружена. Так же добавить проверку, что коэф. масштабирования не 0
//{ERR_OK, ERR_OPEN_FILE, ERR_GET_VALUE, ERR_INCORRECT_VALUE, ERR_NOT_INIT_FIGURE, ERR_NOT_INIT_SCENE};
void process_error(errors_t rc)
{
    switch (rc)
    {
    case ERR_OPEN_FILE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка при открытии файла");
        break;
    case ERR_GET_VALUE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка при чтении очередного значения из файла");
        break;
    case ERR_INCORRECT_VALUE_EDGES:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: число ребер не может быть меньше 1");
        break;
    case ERR_INCORRECT_VALUE_VERTICES:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: число вершин не может быть меньше 2");
        break;
    case ERR_NOT_INIT_FIGURE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: фигура не инициализирована");
        break;
    case ERR_NOT_INIT_SCENE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: сцена не инициализирована");
        break;
    case ERR_NOT_INIT_FILE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: файл не выбран");
        break;
    case ERR_NOT_INIT_EDGES:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: ребра не инициализированы");
        break;
    case ERR_FIGURE_ALWAYS_INIT:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: фигура уже инциализированна");
        break;
    case ERR_ZERO_SCALE_VALUE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: коэффициенты масштабирования не могут быть равны 0");
        break;
    case ERR_DUBLICATE_EDGE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: ребра не могут дублироваться");
        break;
    case ERR_INDEX_EDGE_TOO_LARGE:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: индекс вершины в ребре превышает число вершин");
        break;
    case ERR_ALLOCATE_MEM:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка выделения памяти");
        break;
    case ERR_NOT_INIT_VERTICES:
        QMessageBox::critical(NULL, "Error", "Возникла ошибка: вершины не инициализированны");
        break;
    }
}
