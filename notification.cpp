#include "notification.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QObject>

notification::notification()
{
    num=0 ;
e_id=0 ;
titre="" ;
body="" ;
r_id=0 ;

}

notification::notification(int num , int e_id , QString body, QString titre , int r_id)
{
     this->num=num ;
    this->e_id=e_id ;
        this->titre=titre ;
    this->body=body ;
    this->r_id=r_id ;

}


void notification::set_num(int num)
{
     this->num=num ;
}
void notification::sete_id(int e_id)
{
     this->e_id=e_id ;
}
void notification::set_titre (QString titre)
{
    this->titre=titre ;
}
void notification::set_body(QString body )
{
    this->body=body ;
}
void notification::setr_id(int r_id)
{
    this->r_id=r_id ;
}


bool notification::ajouter()
 {

  QSqlQuery query;
  QString num_string= QString::number(num);
  QString e_id_string= QString::number(e_id);
   QString r_id_string= QString::number(r_id);
       query.prepare("INSERT INTO notification  ( num , EMETTEUR_ID , titre ,  BODY , RECEPTEUR )"
                     "VALUES (:num  , :e_id , :titre , :body ,  :r_id  ) ");
            query.bindValue(":num",num_string);
       query.bindValue(":e_id",e_id_string);
           query.bindValue(":titre",titre);
       query.bindValue(":body",body);
        query.bindValue(":r_id",r_id_string);


       return   query.exec() ;

 }

QSqlQueryModel* notification::afficher(int id)
{  QString id_test= QString::number(id);
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery query ;
    /*QSqlQuery query , query_test1 , query_test2 ;

     query_test1.prepare("SELECT num , emetteur_id , titre from notification order by num") ;
    query_test1.exec() ;
    if (query_test1.first()!=NULL)
    {
        while (query_test1.value(0).toString()!=NULL)
        {
    query_test1.prepare("INSERT INTO echange  ( id , titre , num)"
                        "VALUES (:id , :prenom , :titre )");
          query_test2.bindValue(":id",query_test1.value(1).toString());
           query_test2.bindValue(":prenom",query_test1.value(2).toString());
           query_test2.bindValue(":titre",query_test1.value(0).toString());
          query_test2.exec() ;
        }}*/
    QString res ;
       query.prepare("SELECT num , emetteur_id , titre from notification where RECEPTEUR like '%"+id_test+"%' order by num") ;
      // query.bindValue(":id_test",id_test);

       query.exec();

       query.first();
if (query.first()!=NULL)
{
    while (query.value(0).toString()!=NULL)
    {  QString res ;
        QSqlQuery query3;
        query3.prepare("SELECT prenom from employes where id=:idd") ;
 query3.bindValue(":idd",query.value(1).toString());
        query3.exec();
        query3.first() ;

        QSqlQuery query2;
        query2.prepare("INSERT INTO echange  ( id , prenom , titre)"
                      "VALUES (:id , :prenom , :titre )");
        query2.bindValue(":id",query.value(1).toString());
         query2.bindValue(":prenom",query3.value(0).toString());
         query2.bindValue(":titre",query.value(2).toString());
        query2.exec() ;
        query.next() ;
    }
}
        //res= query.value(0).toString();
        // model->setQuery("SELECT prenom From employes where id like '%"+res+"%'") ;
    model->setQuery("SELECT prenom , titre From echange ") ;
    /*query.bindValue(":id_test",id_test);
     query.bindValue(":res",res);*/

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("")) ;
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("")) ;

      query.prepare("DELETE from echange") ;
      query.exec() ;

              return model ;

}


bool notification::ajouter_msg()
 {

  QSqlQuery query;
  QString num_string= QString::number(num);
  QString e_id_string= QString::number(e_id);
   QString r_id_string= QString::number(r_id);
       query.prepare("INSERT INTO chat  ( num , EMETTEUR_ID , titre ,  BODY , RECEPTEUR )"
                     "VALUES (:num  , :e_id , :titre , :body ,  :r_id  ) ");
            query.bindValue(":num",num_string);
       query.bindValue(":e_id",e_id_string);
           query.bindValue(":titre",titre);
       query.bindValue(":body",body);
        query.bindValue(":r_id",r_id_string);


       return   query.exec() ;

 }

QString notification::afficher_public(QString id_test1)
{

                  QSqlQuery qry;
                  QString titre_p="public" ;
                  qry.prepare("SELECT num , emetteur_id , body from chat where titre=:titre order by num");

                  qry.bindValue(":titre", titre_p);

                  qry.exec() ;
                   qry.first() ;
                 QString msg="" ;
                 if (qry.first()!=NULL)
                 {
                     while (qry.value(0).toString()!=NULL)
                     {
                         if (qry.value(1).toString()==id_test1)
                         { msg= msg+"vous :   "+qry.value(2).toString()+"\r\r" ;
                    qry.next() ; }
                         else {
                             QSqlQuery query2;
                             query2.prepare("SELECT prenom from employes where id=:idd") ;
                      query2.bindValue(":idd",qry.value(1).toString());
                             query2.exec();
                             query2.first() ;
                             msg=msg +query2.value(0).toString()+ " :   "+qry.value(2).toString()+"\r\r" ;
                                                 qry.next() ;
                         }

                        } }
                  return msg ;

}
