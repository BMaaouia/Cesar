#ifndef SPONSOR_H
#define SPONSOR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QWidget>
class sponsor
{
private:

    QString nom;
    int argent;
public:
    sponsor();
    sponsor(QString,int);

    QString getnom(){return nom;}
    int getargent(){return argent;}


    void setnom(QString nom){this->nom=nom;}
    void setargent(int argent){this->argent=argent;}


bool AjouterSponsor();

bool revenue();
};

#endif // SPONSOR_H
