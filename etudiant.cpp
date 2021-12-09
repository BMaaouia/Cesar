#include "etudiant.h"

employe::employe()
{
id=0 ;
nom="" ;
prenom="" ;
e_mail="" ;
specialite="" ;
experience="" ;
grade="" ;

}

employe::employe(int id , QString nom , QString prenom , QString e_mail , QString specialite , QString experience , QString grade)
{
    this->id=id ;
    this->nom=nom ;
    this->prenom=prenom ;
    this->e_mail=e_mail ;
    this->specialite=specialite ;
    this->experience=experience ;
    this->grade=grade  ;

}
