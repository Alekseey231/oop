#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <figure.h>
#include <task.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void create_error_window(std::string title, std::string message);

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
