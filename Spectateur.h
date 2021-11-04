#ifndef Spectateur_H
#define Spectateur_H
#include <QString>
#include <QSqlQueryModel>
class Spectateur
{
public:
    Spectateur();
    Spectateur(int,QString,QString,QString,QString);
    int getid();
    QString getsexe();
    QString getnom();
    QString getprenom();
    QString getemail();
    void setid(int);
    void setsexe(QString);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id, QString sexe,QString nom, QString prenom, QString email);


private:
    int id;
    QString nom,prenom,sexe,email;
};

#endif // Spectateur_H
