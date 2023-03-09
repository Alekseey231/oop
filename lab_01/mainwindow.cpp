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
    task.file.name = filename.toStdString();
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

    transformation_t transformation = {.dx = ui->move_dx->text().toDouble(),
                                       .dy = ui->move_dy->text().toDouble(),
                                       .dz = ui->move_dz->text().toDouble()};
    task.transformation_param.transform = transformation;
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
    transformation_t transformation = {.dx = ui->angle_dx->text().toDouble(),
                                       .dy = ui->angle_dy->text().toDouble(),
                                       .dz = ui->angle_dz->text().toDouble()};
    task.transformation_param.transform = transformation;
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
    errors_t rc = ERR_OK;
    task_t task;
    init_task(task);
    task.type = SCALE;
    task.view.scene = ui->graphicsView->scene();
    transformation_t transformation = {.dx = ui->scale_dx->text().toDouble(),
                                       .dy = ui->scale_dy->text().toDouble(),
                                       .dz = ui->scale_dz->text().toDouble()};
    if (transformation.dx == 0 || transformation.dy == 0 || transformation.dz == 0)
    {
        rc = ERR_ZERO_SCALE_VALUE;
    }

    if (rc == ERR_OK)
    {
        task.transformation_param.transform = transformation;

        rc = process_event(task);
        if (rc == ERR_OK)
        {
            task.type = DRAW;
            rc = process_event(task);
        }
    }
    process_error(rc);
}
