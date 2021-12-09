#include "joueur.h"
#include<QSqlQuery>
#include<QtDebug>
Joueur::Joueur()
{
id=0;classement=0; nom =" "; prenom=" " ;domainedesport=" "; nationalite=" " ;
}

Joueur::Joueur(int id,int classement,QString nom ,QString prenom,QString domainedesport,QString nationalite)
{this->id=id; this ->nom=nom; this ->prenom=prenom; this->classement=classement;
this ->domainedesport=domainedesport; this->nationalite=nationalite; }
int Joueur:: getid() {return id;}
int Joueur::getclassement() {return classement;}
QString Joueur:: getnom(){return nom;}
QString Joueur:: getprenom(){return prenom;}
QString Joueur:: getdomainedesport(){return domainedesport;}
QString Joueur::getnationalite() {return nationalite;}
void Joueur :: setclassement (int classement) {this->classement=classement;}
void Joueur :: setid(int id){this -> id = id;}
void Joueur :: setnom(QString nom){this -> nom=nom;}
void Joueur ::setprenom(QString prenom ) {this -> prenom=prenom;}
void Joueur ::setdomainedesport (QString domainedesport){this -> domainedesport = domainedesport;}
void Joueur :: setnationalite (QString nationalite ) {this -> nationalite=nationalite;}
bool Joueur :: ajouter()
{
QSqlQuery query;
QString idstring=QString::number(id);
QString classementstring=QString::number(classement);
    query.prepare("INSERT INTO JOUEUR (ID, CLASSEMENT, NOM,PRENOM,DOMAINEDESPORT,NATIONALITE) "
                  "VALUES (:id, :classement, :nom, :prenom, :domainedesport, :nationalite )");
    query.bindValue(":id", idstring);
    query.bindValue(":classement", classementstring);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
     query.bindValue(":domainedesport", domainedesport);
    query.bindValue(":nationalite" , nationalite);
   return query.exec();
    }
bool Joueur::supprimer(int id )
    {
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from JOUEUR where id = :id ");
    query.bindValue(":id", res);
    return    query.exec();
    }
    QSqlQueryModel * Joueur::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from JOUEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("classement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("domainedesport"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nationalite"));
        return model;
    }

    bool Joueur::modifier(int id ,int classement ,QString nom ,QString prenom,QString domainedesport,QString nationalite)
    {
    QSqlQuery query;
     QString idString= QString::number(id);
    QString classementString= QString::number(classement);



    query.prepare("UPDATE JOUEUR set ID= :ID , CLASSEMENT= :CLASSEMENT , NOM= :NOM , PRENOM= :PRENOM, DOMAINEDESPORT= :DOMAINEDESPORT, NATIONALITE= :NATIONALITE where ID= :ID" );
    query.bindValue(":id", idString);
    query.bindValue(":classement", classementString);
    query.bindValue(": nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":domainedesport",domainedesport);
    query.bindValue(":nationalite", nationalite);
    return    query.exec();
    }


    QSqlQueryModel * Joueur::tri()
    {
        QSqlQueryModel *model= new QSqlQueryModel;
        QSqlQuery *q=new QSqlQuery();
        q->prepare("SELECT * FROM JOUEUR order by classement asc");
        q->exec();
        model->setQuery(*q);
        return  model;
    }




    QSqlQueryModel * Joueur::rechercher(QString rech)
    {
            QSqlQueryModel * model= new QSqlQueryModel();

                model->setQuery("select * from JOUEUR where id LIKE '"+rech+"%'");
            return model;
    }





