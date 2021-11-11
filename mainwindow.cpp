#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "terrain.h"
#include <QMessageBox>
#include <QItemSelectionModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_affiche->setModel(T.afficher());
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,8}"),NULL));
    ui->lineEdit_capacite->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,6}"),NULL));
    ui->lineEdit_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,10}"),NULL));
    ui->lineEdit_emplacement->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,10}"),NULL));
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
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(T.recherche_t());

}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView_affiche->setModel(T.afficher());
    ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_pushButton_supprime_clicked()
{
    Terrain T1;
    T1.set_id(ui->tableView_affiche->selectionModel()->currentIndex().data().toInt());
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
    Terrain T1;
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(T1.recherche_t());
    int id=ui->comboBox_3->currentText().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString emplacement=ui->lineEdit_emplacement->text();
    QString type=ui->comboBox_type->currentText();
    int capacite=ui->lineEdit_capacite->text().toInt();
    QString etat=ui->comboBox_etat->currentText();

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



    ui->tableView_affiche->setModel(T.afficher());
}

void MainWindow::on_pushButton_tri_clicked()
{
    ui->tableView_affiche->setModel(T.tri_t());

}

