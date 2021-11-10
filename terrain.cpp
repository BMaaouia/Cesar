#include "terrain.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QTableView>
#include <QSqlQueryModel>
#include <QString>

Terrain::Terrain()
{
    id_t=0;
    nom_t="";
    etat_t="";
    emplacement_t="";
    capacite_t=0;
    type_t="";

}

Terrain::Terrain(int id,int capacite,QString etat, QString nom,QString type, QString emplacement)
{
    this->id_t=id;
    this->nom_t=nom;
    this->emplacement_t=emplacement;
    this->etat_t=etat;
    this->capacite_t=capacite;
    this->type_t=type;
}




bool Terrain ::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id_t);
    QString capacite_string= QString::number(capacite_t);
          query.prepare("INSERT INTO TERRAIN (ID ,CAPACITE , ETAT, NOM ,TYPE , EMPLACEMENT) "
                        "VALUES (:id_t, :capacite_t, :etat_t, :nom_t, :type_t, :emplacement_t)");
          query.bindValue(":id_t", id_string);
          query.bindValue(":nom_t", nom_t);
          query.bindValue(":type_t", type_t);
          query.bindValue(":capacite_t", capacite_string);
          query.bindValue(":emplacement_t", emplacement_t);
          query.bindValue(":etat_t", etat_t);
        return   query.exec();

}


QSqlQueryModel *Terrain::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from terrain");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Emplacement"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Capacite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type"));

    return model;
}

bool Terrain::supprimer(int id)
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare("DELETE FROM TERRAIN WHERE ID = :id_t");
    query.bindValue(":id_t", id_string);
    return    query.exec();
}

bool Terrain::modifier(int id,int capacite,QString etat, QString nom,QString type, QString emplacement)
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString capacite_string= QString::number(capacite);
    query.prepare("UPDATE TERRAIN SET ID= :id_t, CAPACITE = :capacite_t, ETAT= :etat_t, NOM = :nom_t, TYPE = :type_t,EMPLACEMENT= :emplacement_t WHERE ID =:id_t ");
    query.bindValue(":id_t", id_string);
    query.bindValue(":nom_t", nom);
    query.bindValue(":type_t", type);
    query.bindValue(":capacite_t", capacite_string);
    query.bindValue(":emplacement_t", emplacement);
    query.bindValue(":etat_t", etat);

    return    query.exec();
}

QSqlQueryModel * Terrain::tri_t()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM terrain ORDER BY capacite");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Emplacement"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Capacite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type"));


    return model;
}

QStringList Terrain::recherche_t(){
    QSqlQuery query;
    query.prepare("select ID from TERRAIN");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
