#include "sponsor.h"

sponsor::sponsor()
{
    nom="";
    argent=0;
}

sponsor::sponsor(QString nom,int argent)
{
    this->nom=nom;
    this->argent=argent;


}
bool sponsor::AjouterSponsor()
{
QSqlQuery query;
QString argent_s= QString::number(argent);

query.prepare("insert into SPONSOR (NOM,ARGENT)" "values(:nom, :argent)");
query.bindValue(":nom",nom);
query.bindValue(":argent",argent_s);

return query.exec();

}

bool sponsor::revenue()
{
QSqlQuery query;
QString argent_s= QString::number(argent);

query.prepare("select sum(ARGENT) from SPONSOR");

query.bindValue(":argent",argent_s);

return query.exec();


}



