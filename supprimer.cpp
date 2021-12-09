#include "supprimer.h"
#include "ui_supprimer.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QIntValidator>

supprimer::supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer)
{
    ui->setupUi(this);
}

supprimer::~supprimer()
{
    delete ui;
}

//void supprimer::on_supp_bouton_clicked()
//{
//employe e1  ;
  //  e1.setid(ui->supp_id->text().toInt()) ;
    //bool test=e1.supprimer(e1.getid()) ;
    //QMessageBox msgBox1 ;
    //if (test)
    //{ msgBox1.setText("Suppression avec succes.") ;


    //}
    //else
      //  msgBox1.setText("Echec de suppression .") ;



//}
