#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QWidget>

class Materiel
{
private:

    QString nom;
    int cout,quantite;
public:
    Materiel();
    Materiel(QString,int,int);

    QString getnom(){return nom;}
    int getcout(){return cout;}
    int getquantite(){return quantite;}

    void setnom(QString nom){this->nom=nom;}
    void setcout(int cout){this->cout=cout;}
    void setquantite(int quantite){this->quantite=quantite;}

bool AjouterMateriel();
};

#endif // MATERIEL_H
