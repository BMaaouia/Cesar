#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "terrain.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_ajout_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_supprime_clicked();

    void on_pushButton_modif_clicked();

    void on_pushButton_tri_clicked();

private:
    Ui::MainWindow *ui;
    Terrain T;

};

#endif // MAINWINDOW_H
