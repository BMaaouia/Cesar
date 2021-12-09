#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>

class Etudiant
{
public:
    Etudiant();
    Etudiant(int , QString ,QString ,QString ,QString ,QString ,QString  ) ;
private:
   int id ;
   QString nom , prenom , e_mail , specialite , experience , grade ;
   int getid() {return id ; } ;
   QString getnom (){return nom ;} ;
   QString getprenom() {return prenom ; } ;
   QString gete_mail() {return e_mail ; } ;
   QString getspecialite() {return specialite ; } ;
   QString getexperience() {return experience ; } ;
   QString getgrade() {return grade ; } ;
   void setid(int) ;
   void setnom (QString) ;
   void setprenom(QString) ;
   void sete_mail(QString) ;
   void setspecialite(QString) ;
   void setexperience(QString) ;
   void setgrade(QString) ;
};

#endif // ETUDIANT_H
