#ifndef Spectateur_H
#define Spectateur_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>


class Spectateur
{
public:
    Spectateur();
    Spectateur(int,QString,QString,QString,QString,QString);
    int getid();
    QString getsexe();
    QString getDate_naissance();
    QString getnom();
    QString getprenom();
    QString getemail();
    void setid(int);
    void setsexe(QString);
    void setDate_naissance(QString);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id,QString sexe,QString date_naissance,QString nom, QString prenom, QString email);
    QSqlQueryModel* recherche_Spectateur(const QString&);
    QSqlQueryModel * tridate_naissance();
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * tri_id();


private:
    int id;
    QString sexe,date_naissance, nom,prenom,email;


};

#endif // Spectateur_H
