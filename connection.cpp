#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("employe-bd");
db.setUserName("rayen");//inserer nom de l'utilisateur
db.setPassword("Rayen123esprit");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
