#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <task.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    task_t task;
    init_task(task);
    task.type = QUIT;
    process_event(task);
    // delete ui->graphicsView->scene();
    delete ui;
}

//реализовано следующее поведение: если юзер выбрал некорректный файл, текущая фигура очищается
void MainWindow::on_load_file_clicked()
{
    task_t task;
    init_task(task);
    task.type = READ_FILE;
    task.view.scene = ui->graphicsView->scene();
    QString filename = QFileDialog::getOpenFileName(0, "Open", "../lab_01/", "*.txt");
    task.file.path_to_file = filename.toStdString();
    if (filename.length() != 0)
    {
        errors_t rc = process_event(task);
        if (rc == ERR_OK)
        {
            task.type = DRAW;
            rc = process_event(task);
        }
        process_error(rc);
    }
}

void MainWindow::on_move_clicked()
{
    task_t task;
    init_task(task);
    task.type = TRANSFORM;
    task.view.scene = ui->graphicsView->scene();
    // TODO Add double validator
    // TODO Check empty input - zero
    task.transformation_param.transform.dx = ui->move_dx->text().toDouble();
    task.transformation_param.transform.dy = ui->move_dy->text().toDouble();
    task.transformation_param.transform.dz = ui->move_dz->text().toDouble();
    auto rc = process_event(task);
    if (rc == ERR_OK)
    {
        task.type = DRAW;
        rc = process_event(task);
    }
    process_error(rc);
}

void MainWindow::on_rotate_clicked()
{
    task_t task;
    init_task(task);
    task.type = ROTATE;
    task.view.scene = ui->graphicsView->scene();
    task.transformation_param.transform.dx = ui->angle_dx->text().toDouble();
    task.transformation_param.transform.dy = ui->angle_dy->text().toDouble();
    task.transformation_param.transform.dz = ui->angle_dz->text().toDouble();
    auto rc = process_event(task);
    if (rc == ERR_OK)
    {
        task.type = DRAW;
        rc = process_event(task);
    }
    process_error(rc);
}

void MainWindow::on_scale_clicked()
{
    task_t task;
    init_task(task);
    task.type = SCALE;
    task.view.scene = ui->graphicsView->scene();
    task.transformation_param.transform.dx = ui->scale_dx->text().toDouble();
    task.transformation_param.transform.dy = ui->scale_dy->text().toDouble();
    task.transformation_param.transform.dz = ui->scale_dz->text().toDouble();

    // TODO check scale != 0
    auto rc = process_event(task);
    if (rc == ERR_OK)
    {
        task.type = DRAW;
        rc = process_event(task);
    }
    process_error(rc);
}
