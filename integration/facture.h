#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QTableWidgetItem>
class Facture
{
    QString client,type,date;
    int idfc;
public:
    Facture();
    Facture(int,QString,QString,QString);

    QString getClient(){return client;}
    QString gettype(){return type;}
    QString getdate(){return date;}

    void setClient(QString client){this->client=client;}
    void settype(QString type){this->type=type;}
    void setdate(int date){this->date=date;}

bool AjouterFacture();
QSqlQueryModel* AfficherFacture();
bool ModifierFacture(int,QString,QString,QString);
bool SupprimerFacture(int);
QSqlQueryModel * triID();
QSqlQueryModel * tri_client();
QSqlQueryModel * tri_pay();

QSqlQueryModel * rechercher_dynamique(QString a);
QStringList recherche_m();
QStringList recherche_s();
bool modifier_e(QString nom);

};

#endif // FACTURE_H
