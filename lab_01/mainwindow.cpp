#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <task.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

}

MainWindow::~MainWindow()
{
    delete ui->graphicsView->scene();
    delete ui;
}



void MainWindow::on_load_file_clicked()
{
    task_t task;
    task.type = read_file;

    task.view.scene = ui->graphicsView->scene();
    task.view.scene->addEllipse(0,0,1,1);

    //QString filename = QFileDialog::getOpenFileName(0, "Open", "../", "*.txt");
    //task.file.path_to_file = filename.toStdString();
    task.file.path_to_file = "../lab_01/data.txt";

    errors_t rc = process_event(task);
    qDebug() << rc;
    if(rc == ERR_OK)
    {
        task.type = draw;
        process_event(task);
    }
}



void MainWindow::on_move_clicked()
{
    task_t task;
    task.type = transform;
    task.view.scene = ui->graphicsView->scene();
    // TODO Add double validator
    // TODO Check empty input - zero
    task.transform.dx = ui->move_dx->text().toDouble();
    task.transform.dy = ui->move_dy->text().toDouble();
    task.transform.dz = ui->move_dz->text().toDouble();
    auto rc = process_event(task);
    if(rc == ERR_OK)
    {
        task.type = draw;
        rc = process_event(task);
    }
}


void MainWindow::on_rotate_clicked()
{
    task_t task;
    task.type = rotate;
    task.view.scene = ui->graphicsView->scene();
    task.transform.dx = ui->angle_dx->text().toDouble();
    task.transform.dy = ui->angle_dy->text().toDouble();
    task.transform.dz = ui->angle_dz->text().toDouble();
    auto rc = process_event(task);
    if(rc == ERR_OK)
    {
        task.type = draw;
        rc = process_event(task);
        //добавить вывод сообщений о ошибках
    }
}


void MainWindow::on_scale_clicked()
{
    task_t task;
    task.type = scale;
    task.view.scene = ui->graphicsView->scene();
    task.transform.dx = ui->scale_dx->text().toDouble();
    task.transform.dy = ui->scale_dy->text().toDouble();
    task.transform.dz = ui->scale_dz->text().toDouble();
    auto rc = process_event(task);
    if(rc == ERR_OK)
    {
        task.type = draw;
        rc = process_event(task);
        //добавить вывод сообщений о ошибках
    }
}

