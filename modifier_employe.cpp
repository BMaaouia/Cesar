#include "modifier_employe.h"
#include "ui_modifier_employe.h"
#include "employe.h"
#include "modifier.h"
#include <QMessageBox>

modifier_employe::modifier_employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_employe)
{
    ui->setupUi(this);
    /*modifier m ;
    int id ;
    id=m.valeur() ;
    QString id_m=QString::number(id);
    ui->id_space->setText(id_m) ;*/


}

modifier_employe::~modifier_employe()
{
    delete ui;
}

void modifier_employe::on_Ajouter_bouton_clicked()
{
    employe e ;
    int id=ui->id_space->text().toInt() ;
    QString nom=ui->nom_space->text();
    QString prenom=ui->prenom_space->text() ;
    QString e_mail=ui->e_mail_space->text() ;
    QString specialite=ui->specialite_space->currentText() ;
    QString experience=ui->experience_space->text() ;
    QString grade=ui->grade_space->currentText() ;
    QString date=ui->date_space->text() ;
    bool test=e.modifier(id , nom , prenom , e_mail , specialite , experience , grade , date ) ;
    QMessageBox msgBox ;
    if (test)
      {  msgBox.setText("modification avec succes.") ;
      }
    else
        msgBox.setText("Echec de modification.") ;
    msgBox.exec() ;
}
