#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QString>
#include <QSqlQueryModel>
#include <QObject>

class notification
{
private :
    int num ;
   int e_id ;
    QString  titre ;
    QString   body ;
   int r_id ;
public:
    notification();
    notification(int , int  , QString , QString  , int) ;

   int gete_id() {return e_id ; } ;
   int get_num() {return num ; } ;
    QString get_titre() {return titre ; } ;
    QString get_body() {return body ; } ;
      int getr_id() {return r_id ; } ;
        void set_num(int) ;
    void sete_id(int) ;
    void set_titre (QString) ;
    void set_body (QString) ;
      void setr_id (int) ;
     bool ajouter() ;
      QSqlQueryModel* afficher(int ) ;
      bool supprimer(int) ;
      bool ajouter_msg() ;
      QString afficher_public( QString ) ;
};

#endif // NOTIFICATION_H
