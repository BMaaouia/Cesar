#ifndef TERRAIN_H
#define TERRAIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
class Terrain
{


private:
    int id_t;
    int capacite_t;
    QString type_t;
    QString nom_t;
    QString emplacement_t;
    QString etat_t;
public:

    Terrain();
    Terrain(int id,int capacite,QString etat, QString nom,QString type, QString emplacement);
    int get_id(){return id_t;}

    QString get_type(){return type_t;}
    QString get_nom(){return nom_t;}
    QString get_emplacement(){return emplacement_t;}
    int get_capacite(){return capacite_t;}
    QString get_etat(){return etat_t;}
    void set_id(int id){this->id_t=id;}

    void set_type(QString type){this->type_t=type;}
    void set_nom(QString nom){this->nom_t=nom;}
    void set_emplacement(QString emplacement){this->emplacement_t=emplacement;}
    void set_capacite(int capacite){this->capacite_t=capacite;}
    void set_etat(QString etat){this->etat_t=etat;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int id,int capacite,QString etat, QString nom,QString type, QString emplacement);
    QSqlQueryModel * tri_t();
    QStringList recherche_t();


};

#endif // TERRAIN_H
