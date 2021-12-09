#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include <QObject>

class employe
{
public:
    employe();
    employe(int , QString ,QString ,QString ,QString ,QString ,QString ,QString  ) ;
    int getid() {return id ; } ;
    QString getnom (){return nom ;} ;
    QString getprenom() {return prenom ; } ;
    QString gete_mail() {return e_mail ; } ;
    QString getspecialite() {return specialite ; } ;
    QString getexperience() {return experience ; } ;
    QString getgrade() {return grade ; } ;
    QString getdate() {return date ; } ;
    void setid(int) ;
    void setnom (QString) ;
    void setprenom(QString) ;
    void sete_mail(QString) ;
    void setspecialite(QString) ;
    void setexperience(QString) ;
    void setgrade(QString) ;
    void setdate(QString) ;
    bool ajouter() ;
    QSqlQueryModel* afficher() ;
    bool supprimer(int) ;
    bool modifier (int , QString ,QString ,QString ,QString ,QString ,QString , QString  ) ;
    QSqlQueryModel * rechercher(QString rech) ;
    QSqlQueryModel* trinom();
       QSqlQueryModel* triref();
       QSqlQueryModel* triprenom();
       QSqlQueryModel* afficher_liste() ;
private:
   int id ;
   QString nom , prenom , e_mail , specialite , experience , grade , date ;

};

#endif // EMPLOYE_H
