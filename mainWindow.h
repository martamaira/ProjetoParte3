#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sculptor.h"
#include "vector"
#include "plotter.h"
#include <QMainWindow>
#include <QWidget>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Desenho();
    void quit();
private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};
#endif // MAINWINDOW_H
