#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Spectateur.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100,900,this));
    ui->tab_Spectateur->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString sexe=ui->le_sexe->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    Spectateur E(id,sexe,nom,prenom,email);



    bool test=E.ajouter();
    QMessageBox msgBox;

    if (test)
        msgBox.setText("Ajout avec succes.");
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();


}

void MainWindow::on_pb_supprimer_clicked()
{
    Spectateur E1;
    E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

    if (test)
        msgBox.setText("Suppression avec succes.");
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
        ui->tab_Spectateur->setModel(E1.afficher());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
 ui->tab_Spectateur->setModel(E.afficher());
}

void MainWindow::on_modif_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString sexe=ui->le_sexe_2->text();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString email=ui->le_email_2->text();
QMessageBox msgBox;
    bool test=E.modifier(id,sexe,nom,prenom,email);
    if (test)
        msgBox.setText("modification avec succes.");
    else
        msgBox.setText("Echec de modification");
        msgBox.exec();
    ui->tab_Spectateur->setModel(E.afficher());
}


