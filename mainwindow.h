#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Spectateur.h"

#include <QMainWindow>

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_modif_clicked();



private:
    Ui::MainWindow *ui;
    Spectateur E;
};

#endif // MAINWINDOW_H
