#include "modifier.h"
#include "ui_modifier.h"
#include "modifier_employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QObject>
#include <QMessageBox>

modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_commandLinkButton_clicked()
{ int test ;
    QSqlQuery qry;

     qry.prepare("select * from employes where ID = :id ");
     test=ui->employe_modif->text().toInt() ;
QString test1=QString::number(test);
     qry.bindValue(":id", test1);

     qry.exec();

      QMessageBox msgBox ;

    if (qry.first()==NULL)
    {
  msgBox.setText("aucun employe de cet id ! veuillez entrer une autre id svp") ;
  msgBox.exec() ;
    }
    else {
    modifier_employe m ;
    m.exec() ;
    }

}

/*int modifier::valeur ()
{int test ;
    test=ui->employe_modif->text().toInt() ;
    return test ;
}*/
