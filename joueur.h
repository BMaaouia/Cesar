#ifndef JOUEUR_H
#define JOUEUR_H

#include<QString>
#include<qsqlquery.h>
#include<QSqlQueryModel>
class Joueur
{
public:
    Joueur();
    Joueur (int,int,QString,QString,QString,QString);
    int getid();
    int getclassement();
    QString getnom();
    QString getprenom();
    QString getdomainedesport();
    QString getnationalite();
    void setid(int);
    void setclassement (int);
    void setnom(QString);
    void setprenom(QString);
    void setdomainedesport (QString);
    void setnationalite (QString);
bool ajouter () ;
QSqlQueryModel   *afficher();
bool supprimer (int) ;
bool modifier (int,int,QString,QString,QString,QString) ;
QSqlQueryModel * rechercher(QString);
     QSqlQueryModel *tri();
private :
    int id,classement;
    QString nom, prenom,domainedesport,nationalite;

};

#endif // JOUEUR_H
