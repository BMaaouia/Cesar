#include "Spectateur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Spectateur::Spectateur()
{
    id=0;sexe="";nom="";prenom=" ";email=" ";
}

Spectateur::Spectateur(int id,QString nom,QString sexe,QString prenom,QString email)
{this->id=id;this->sexe=sexe; this->nom=nom ;this->prenom=prenom;this->email=email;}

int Spectateur::getid(){return id;};
QString Spectateur::getsexe() {return sexe;}
QString Spectateur::getnom() {return nom;}
QString Spectateur::getprenom() {return prenom;}
QString Spectateur::getemail() {return email;}
void Spectateur::setid(int id){this->id=id;}
void Spectateur::setsexe(QString sexe){this->sexe=sexe;}
void Spectateur::setnom(QString nom){this->nom=nom;}
void Spectateur::setprenom(QString prenom){this->prenom=prenom;}
void Spectateur::setemail(QString email){this->email=email;}//zz
bool Spectateur::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO Spectateur (id,sexe, nom, prenom, email) "
                        "VALUES (:id,:sexe, :nom, :prenom,:email)");
          query.bindValue(":id", id_string);
          query.bindValue(":sexe", sexe);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":email", email);
         return query.exec();

}

QSqlQueryModel* Spectateur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel;

          model->setQuery("SELECT* FROM Spectateur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Sexe"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("email"));
   return model;
}

bool Spectateur::supprimer(int id)
{
    QSqlQuery query;
           query.prepare(" DELETE FROM Spectateur WHERE id=:id");
           query.bindValue(":id",id);

         return query.exec();

}

bool Spectateur::modifier(int id,QString sexe, QString nom, QString prenom,QString email)
{
    QSqlQuery query;
    query.prepare("UPDATE Spectateur SET ID=:id, NOM=:nom, PRENOM=:prenom WHERE ID=:id;");
    query.bindValue(":id",id);
    query.bindValue(":sexe", sexe);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email", email);
    return  query.exec();
}








