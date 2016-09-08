#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_open_button_clicked();
    void on_convert_button_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
