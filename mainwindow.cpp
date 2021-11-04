#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "terrain.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_affiche->setModel(T.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajout_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString emplacement=ui->lineEdit_emplacement->text();
    QString type=ui->comboBox_type->currentText();
    int capacite=ui->lineEdit_capacite->text().toInt();
    QString etat=ui->comboBox_etat->currentText();

   Terrain T(id,capacite,etat,nom,type,emplacement);

   bool test=T.ajouter();
   if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("Ajouter un terrain"),
                        QObject::tr("terrain ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       QString objet="AJOUT terrain";
       QString message=" Votre terrain a été ajouté avec succés" ;}

       else {
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }

}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tableView_affiche->setModel(T.afficher());

}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView_affiche->setModel(T.afficher());
    ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_pushButton_supprime_clicked()
{
    Terrain T1;
    T1.set_id(ui->lineEdit_id_2->text().toInt());
    bool test=T1.supprimer(T1.get_id());

    QMessageBox msgBox;

    if(test)

        msgBox.setText("Suppression avec succes.");
    else
    msgBox.setText("Echec ");
    msgBox.exec();

ui->tableView_affiche->setModel(T.afficher());

}

void MainWindow::on_pushButton_modif_clicked()
{
    int id=ui->lineEdit_id_3->text().toInt();
    QString nom=ui->lineEdit_nom_2->text();
    QString emplacement=ui->lineEdit_emplacement_2->text();
    QString type=ui->comboBox_type_2->currentText();
    int capacite=ui->lineEdit_capacite_2->text().toInt();
    QString etat=ui->comboBox_etat_2->currentText();
    Terrain T1;

    bool test=T1.modifier(id,capacite,etat,nom,type, emplacement);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie une vehicule"),
                          QObject::tr("vehicule modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tableView_affiche->setModel(T1.afficher());
}
