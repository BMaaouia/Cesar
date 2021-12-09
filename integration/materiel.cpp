#include "materiel.h"

Materiel::Materiel()
{
    nom="";
    quantite=0;
    cout=0;
}


Materiel::Materiel(QString nom,int quantite,int cout)
{
    this->nom=nom;
    this->quantite=quantite;
    this->cout=cout;

}
bool Materiel::AjouterMateriel()
{
QSqlQuery query;
QString quantite_s= QString::number(quantite);
QString cout_s= QString::number(cout);
query.prepare("insert into MATERIAUX (NOM_M,QUANTITE,COUT)" "values(:nom, :quantite,:cout)");
query.bindValue(":nom",nom);
query.bindValue(":quantite",quantite_s);
query.bindValue(":cout",cout_s);
return query.exec();

}
