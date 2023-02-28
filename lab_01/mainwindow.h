#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <task.h>
#include <figure.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_load_file_clicked();

    void on_move_clicked();

    void on_rotate_clicked();


    void on_scale_clicked();

private:
    Ui::MainWindow *ui;
    figure_t figure;

};
#endif // MAINWINDOW_H
