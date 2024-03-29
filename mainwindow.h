#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "2modules/capacitycalc.h"

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
    void on_pb_2_clicked();

    void on_pb_3_clicked();

    void on_pb_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
