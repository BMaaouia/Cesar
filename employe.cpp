#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QObject>

employe::employe()
{
id=0 ;
nom="" ;
prenom="" ;
e_mail="" ;
specialite="" ;
experience="" ;
grade="" ;
date="" ;

}

employe::employe(int id , QString nom , QString prenom , QString e_mail , QString specialite , QString experience , QString grade , QString date)
{
    this->id=id ;
    this->nom=nom ;
    this->prenom=prenom ;
    this->e_mail=e_mail ;
    this->specialite=specialite ;
    this->experience=experience ;
    this->grade=grade  ;
    this->date=date  ;

}

void employe::setid(int id)
{
     this->id=id ;
}
void employe::setnom (QString nom)
{
    this->nom=nom ;
}
void employe::setprenom(QString prenom )
{
    this->prenom=prenom ;
}
void employe::sete_mail(QString e_mail)
{
    this->e_mail=e_mail ;
}
void employe::setspecialite(QString specialite )
{
    this->specialite=specialite ;
}
void employe::setexperience(QString experience )
{
    this->experience=experience ;
}
void employe::setgrade(QString grade )
{
    this->grade=grade  ;
}

void employe::setdate(QString date )
{
    this->date=date  ;
}

bool employe::ajouter()
 {


  QSqlQuery query;
  QString id_string= QString::number(id);
       query.prepare("INSERT INTO EMPLOYES  ( ID, NOM , PRENOM , E_MAIL , SPECIALITE, EXPERIENCE , GRADE , DATE_EMPLOYE)"
                     "VALUES (:id , :nom , :prenom , :e_mail , :specialite, :experience , :grade , :date)");
       query.bindValue(":id",id_string);
       query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
         query.bindValue(":e_mail",e_mail);
      query.bindValue(":specialite",specialite);
       query.bindValue(":experience",experience);
       query.bindValue(":grade",grade);
       query.bindValue(":date",date);

       return   query.exec() ;


 }

bool employe::supprimer(int id)
{
    QSqlQuery query;

         query.prepare("DELETE from employes where ID=:id ");

         query.bindValue(0,id);


         return   query.exec() ;
}


QSqlQueryModel* employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    model->setQuery("SELECT* From employes") ;
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom")) ;
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom")) ;
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail")) ;
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Spécialité")) ;
             model->setHeaderData(5,Qt::Horizontal,QObject::tr("Expérience")) ;
              model->setHeaderData(6,Qt::Horizontal,QObject::tr("Grade")) ;
              model->setHeaderData(7,Qt::Horizontal,QObject::tr("date recrutement")) ;
              return model ;

}

bool employe::modifier(int id1,QString nom1, QString prenom1, QString e_mail1 , QString specialite1 , QString experience1 , QString grade1 , QString date1 )
{
   QSqlQuery query;
   QString id_string= QString::number(id1);


    query.prepare("update employes set ID=:id, NOM=:nom , PRENOM=:prenom , E_MAIL=:e_mail , SPECIALITE=:specialite, EXPERIENCE=:experience , GRADE=:grade , DATE_EMPLOYE=:date where ID=:id");
    query.bindValue(":id", id_string);
    query.bindValue(":nom",nom1);
    query.bindValue(":prenom",prenom1);
    query.bindValue(":e_mail",e_mail1);
 query.bindValue(":specialite",specialite1);
  query.bindValue(":experience",experience1);
  query.bindValue(":grade",grade1);
  query.bindValue(":date",date1);


    return query.exec();
}


QSqlQueryModel * employe::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QString recher="select * from employes where ID like '%"+rech+"%'or NOM like '%"+rech+"%'or PRENOM like '%"+rech+"%'";
        model->setQuery(recher);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
           model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom")) ;
           model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom")) ;
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail")) ;
              model->setHeaderData(4,Qt::Horizontal,QObject::tr("Spécialité")) ;
                 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Expérience")) ;
                  model->setHeaderData(6,Qt::Horizontal,QObject::tr("Grade")) ;
                  model->setHeaderData(7,Qt::Horizontal,QObject::tr("date recrutement")) ;

        return model;
}


/*QSqlQueryModel * employe::tri_t(QString ch , QString o)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY "+ch+" "+o+" ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom")) ;
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom")) ;
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail")) ;
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Spécialité")) ;
             model->setHeaderData(5,Qt::Horizontal,QObject::tr("Expérience")) ;
              model->setHeaderData(6,Qt::Horizontal,QObject::tr("Grade")) ;
              model->setHeaderData(7,Qt::Horizontal,QObject::tr("date recrutement")) ;
              ui->tableView_affiche->setModel(e.tri_t("Nom","ASC"));


    return model;
}*/

QSqlQueryModel * employe::trinom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYES ORDER BY NOM");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom")) ;
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom")) ;
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail")) ;
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Spécialité")) ;
             model->setHeaderData(5,Qt::Horizontal,QObject::tr("Expérience")) ;
              model->setHeaderData(6,Qt::Horizontal,QObject::tr("Grade")) ;
              model->setHeaderData(7,Qt::Horizontal,QObject::tr("date recrutement")) ;
    return model;
}
QSqlQueryModel * employe::triref()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYES ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom")) ;
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom")) ;
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail")) ;
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Spécialité")) ;
             model->setHeaderData(5,Qt::Horizontal,QObject::tr("Expérience")) ;
              model->setHeaderData(6,Qt::Horizontal,QObject::tr("Grade")) ;
              model->setHeaderData(7,Qt::Horizontal,QObject::tr("date recrutement")) ;
    return model;
}
QSqlQueryModel * employe::triprenom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYES ORDER BY PRENOM");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant")) ;
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom")) ;
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom")) ;
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail")) ;
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Spécialité")) ;
             model->setHeaderData(5,Qt::Horizontal,QObject::tr("Expérience")) ;
              model->setHeaderData(6,Qt::Horizontal,QObject::tr("Grade")) ;
              model->setHeaderData(7,Qt::Horizontal,QObject::tr("date recrutement")) ;

    return model;
}


QSqlQueryModel* employe::afficher_liste()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    model->setQuery("SELECT id , nom , prenom , grade From employes") ;
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID")) ;
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom")) ;
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom")) ;
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("Grade")) ;

              return model ;

}
