#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include "notification.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   // void test() ;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_bouton_clicked();


void on_supp_bouton_clicked() ;

void on_pushButton_7_clicked();

void on_pushButton_3_clicked();

void on_pushButton_2_clicked();

void on_rapport_envoyer_clicked();

void on_imprimer_clicked();

void on_radioButton_clicked();

void on_radioButton_2_clicked();

void on_radioButton_3_clicked();

void on_pushButton_4_clicked();

void on_supp_notif_clicked();

void on_pushButton_6_clicked();

void on_ouvrir_chat_clicked();

void on_envoye_prive_clicked();

void on_envoye_public_clicked();

void on_fiche_confirmer_clicked();

void on_pushButton_5_clicked();

void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    employe e ;
    int id_test=999 ;
    notification n ;
    int r_chat ;
    QString prenom1 ;
};
#endif // MAINWINDOW_H


