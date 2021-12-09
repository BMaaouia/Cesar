#include "Spectateur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Spectateur::Spectateur()
{
    id=0;sexe="";date_naissance="";nom="";prenom=" ";email=" ";
}

Spectateur::Spectateur(int id,QString sexe,QString date_naissance,QString nom,QString prenom,QString email)
{this->id=id;this->sexe=sexe;this->date_naissance=date_naissance; this->nom=nom ;this->prenom=prenom;this->email=email;}

int Spectateur::getid(){return id;};
QString Spectateur::getsexe() {return sexe;}
QString Spectateur::getDate_naissance(){return date_naissance;}
QString Spectateur::getnom() {return nom;}
QString Spectateur::getprenom() {return prenom;}
QString Spectateur::getemail() {return email;}
void Spectateur::setid(int id){this->id=id;}
void Spectateur::setsexe(QString sexe){this->sexe=sexe;}
void Spectateur::setDate_naissance(QString date_naissance){this->date_naissance=date_naissance;}
void Spectateur::setnom(QString nom){this->nom=nom;}
void Spectateur::setprenom(QString prenom){this->prenom=prenom;}
void Spectateur::setemail(QString email){this->email=email;}


bool Spectateur::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO Spectateur (id,sexe,date_naissance, nom, prenom, email) "
                        "VALUES (:id,:sexe,:date_naissance, :nom, :prenom,:email)");
          query.bindValue(":id", id_string);
          query.bindValue(":sexe", sexe);
          query.bindValue(":date_naissance", date_naissance);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":email", email);
         return query.exec();

}



QSqlQueryModel* Spectateur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel;

          model->setQuery("SELECT * FROM Spectateur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
   return model;
}

bool Spectateur::supprimer(int id)
{
    QSqlQuery query;
           query.prepare(" DELETE FROM Spectateur WHERE id=:id");
           query.bindValue(":id",id);

         return query.exec();

}

bool Spectateur::modifier(int id,QString sexe,QString date_naissance, QString nom, QString prenom,QString email)
{
    QSqlQuery query;
    query.prepare("UPDATE Spectateur SET ID=:id,sexe=:sexe,date_naissance=:date_naissance, nom=:nom, prenom=:prenom,email=:email WHERE ID=:id");
    query.bindValue(":id",id);
    query.bindValue(":sexe", sexe);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email", email);
    return query.exec();
}

QSqlQueryModel* Spectateur::recherche_Spectateur(const QString &str){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from Spectateur where nom like '"+str+"%' or prenom like '"+str+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model;
}

QSqlQueryModel * Spectateur::tridate_naissance(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Spectateur order by date_naissance ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model;
}
QSqlQueryModel* Spectateur:: tri_nom()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Spectateur order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model;
}
QSqlQueryModel* Spectateur:: tri_id()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Spectateur order by id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model;
}







