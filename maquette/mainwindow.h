#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "joueur.h"
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
    void on_pushButton_6_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_PushButtonModifier_clicked();

    void on_recherche_clicked();

    void on_tri_clicked();

    void on_imp_clicked();

    void on_stat_clicked();

private:
    Ui::MainWindow *ui;
    Joueur Etmp;
};
#endif // MAINWINDOW_H
