#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_7->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,15}"),this));
    ui->lineEdit_8->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,15}"),this));
    ui->lineEdit_9->setValidator(new QIntValidator(0,999999999,this));
    ui->lineEdit_10->setValidator(new QIntValidator(0,999999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit_7->text()!="" && ui->lineEdit_8->text()!="" && ui->lineEdit_10->text()!="" && ui->lineEdit_9->text()!="")
    {
        qDebug()<<"bouton: « afficher Personne » appuyé" ;
            QMessageBox::information(nullptr, QObject::tr("Bouton afficher appuyé"),
                QObject::tr("l’opération est effectuée avec sucées .\n"
                            "Click Cancel pour quitter."), QMessageBox::Cancel);

    }
    else
    {
        qDebug()<<"bouton: « afficher Personne » appuyé" ;
            QMessageBox::warning(nullptr, QObject::tr("Bouton afficher appuyé"),
                    QObject::tr("l’opération n'est pas effectuée .\n"
                                "Click Cancel pour quitter."), QMessageBox::Cancel);

    }


}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->lineEdit_7->text()!="" && ui->lineEdit_8->text()!="" && ui->lineEdit_10->text()!="" && ui->lineEdit_9->text()!="")
    {
        qDebug()<<"bouton: « ajouter Personne » appuyé" ;
            QMessageBox::information(nullptr, QObject::tr("Bouton ajouter appuyé"),
                QObject::tr("l’opération est effectuée avec sucées .\n"
                            "Click Cancel pour quitter."), QMessageBox::Cancel);
    }
    else
    {
        qDebug()<<"bouton: « ajouter Personne » appuyé" ;
            QMessageBox::warning(nullptr, QObject::tr("Bouton ajouter appuyé"),
                    QObject::tr("l’opération n'est pas effectuée .\n"
                                "Click Cancel pour quitter."), QMessageBox::Cancel);

    }
}










