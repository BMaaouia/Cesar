#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#include "modifier.h"
#include "notification.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QPropertyAnimation>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>
#include <QSortFilterProxyModel>
#include <QPainter>
#include <QPdfWriter>
#include"QTextDocumentWriter"
#include <QTextStream>
#include"QDesktopServices"
#include <QFileDialog>
#include <QPrinter>
#include"QFont"
#include"QPen"
#include <QPainter>
#include <QTextDocument>
#include <QDate>
#include <QPrintDialog>
#include <QPropertyAnimation>
#include <QFile>
#include <QDebug>
#include <random>
#include <iostream>
#include <QSystemTrayIcon>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

     QString id_test1=QString::number(id_test);
    ui->setupUi(this);
    ui->id_space->setValidator(new QIntValidator(0,99999999,this)) ;
    ui->Tab1->setModel(e.afficher()) ;
     ui->chat_liste->setModel(e.afficher_liste()) ;
      ui->chat_public->setText(n.afficher_public(id_test1)) ;

    ui->Tab_notif->setModel(n.afficher(id_test)) ;



    QSqlQuery qry;

     qry.prepare("select * from employes where ID = :id ");

     qry.bindValue(":id", id_test1);

     qry.exec();

     qry.first();
    QString id , nom , prenom , e_mail , specialite ,  experience , grade   ;
    qry.first();
    id=qry.value(0).toString();
     nom= qry.value(1).toString();
     prenom=qry.value(2).toString();
     e_mail=qry.value(3).toString();
     specialite=qry.value(4).toString();
     experience=qry.value(5).toString();
     grade=qry.value(6).toString();

     ui->profil_id->setText(id);
     ui->profil_nom->setText(nom);
     ui->profil_prenom->setText(prenom);
     ui->profil_e_mail->setText(e_mail);
     ui->profil_specialite->setText(specialite);
     ui->profil_experience->setText(experience);
     ui->profil_grade->setText(grade);


     ui->profil_id_2->setText(id);
     ui->profil_nom_2->setText(nom);
     ui->profil_prenom_2->setText(prenom);
     ui->profil_e_mail_2->setText(e_mail);
     ui->profil_specialite_2->setText(specialite);
     ui->profil_experience_2->setText(experience);
     ui->profil_grade_2->setText(grade);

    QSqlQuery query;

    query.prepare("select * from fiche_de_paie where employe_id = :id ");

    query.bindValue(":id", id_test1);

    query.exec();

    query.first();
   QString salaire , sante , impot , net , date , date1 , date2   ;
   query.first();
   salaire =query.value(0).toString();
    sante= query.value(1).toString();
    impot=query.value(2).toString();
    net=query.value(4).toString();
    date=query.value(5).toString();
    date1=query.value(6).toString();
    date2=query.value(7).toString();

    ui->date_1->setText(date1);
    ui->date_2->setText(date2);
    ui->date_affec->setText(date);
    ui->salaire->setText(salaire);
    ui->sante->setText(sante);
    ui->impot->setText(impot);
    ui->net->setText(net);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter_bouton_clicked()
{
    int id=ui->id_space->text().toInt() ;
    QString nom=ui->nom_space->text();
    QString prenom=ui->prenom_space->text() ;
    QString e_mail=ui->e_mail_space->text() ;
    QString specialite=ui->specialite_space->currentText() ;
    QString experience=ui->experience_space->text() ;
    QString grade=ui->grade_space->currentText() ;
    QString date=ui->date_space->text() ;
    employe e(id , nom , prenom , e_mail , specialite , experience , grade , date )  ;
    bool test=e.ajouter() ;
    QMessageBox msgBox ;
    if (test)
      {  msgBox.setText("Ajout avec succes.") ;
     ui->Tab1->setModel(e.afficher()) ;
      ui->chat_liste->setModel(e.afficher_liste()) ;}
    else
        msgBox.setText("Echec d'ajout.") ;
    msgBox.exec() ;
}



void MainWindow::on_supp_bouton_clicked()
{
    employe e1  ;
       e1.setid(ui->supp_id->text().toInt()) ;
        int test=e1.supprimer(e1.getid()) ;
        QMessageBox msgBox ;
       if (test)
       { msgBox.setText("Suppression avec succes.") ;
     ui->Tab1->setModel(e.afficher()) ;
       ui->chat_liste->setModel(e.afficher_liste()) ;

        }
        else
            msgBox.setText("Echec de suppression .") ;

       msgBox.exec() ;

}


void MainWindow::on_pushButton_7_clicked()
{
    modifier m ;
    m.exec() ;
}

void MainWindow::on_pushButton_3_clicked()
{ employe e ;
    ui->Tab1->setModel(e.rechercher(ui->recherche_space->text())) ;
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->Tab1->setModel(e.afficher()) ;
}

void MainWindow::on_rapport_envoyer_clicked()
{

    int r_id=ui->rapport_id->text().toInt() ;
    QString body=ui->rapport_body->text();
   /* QSqlQuery qry;
    qry.prepare("select num from( SELECT num, 1 as num FROM notification union select null, 2) notification");
    qry.exec();
       qry.first();
       int num1=1 ;
       if (qry.value(0).toString()==NULL)
       {
           num1=0 ;
       }
         QString num2=QString::number(num1);
       ui->rapport_body->setText(num2) ;*/
    bool test ;
    int r ;
    int o ;

    QSqlQuery qry;
    qry.prepare("select * from notification order by num");
    qry.exec();

    if(qry.first()==NULL)

    {
        o=1 ;

    }
    else {
       qry.last();
       o=qry.value(0).toInt()+1;
    }

    notification n( o , id_test ,body ,"Rapport", r_id ) ;
     test=n.ajouter() ;

        /* do {
   r=rand()%50+1 ;
o++ ;
    notification n( r , id_test ,body , r_id ) ;
     test=n.ajouter() ;
    } while (test==false && o<500) ;

QString r1=QString::number(r);
ui->rapport_body->setText(r1);*/
    QMessageBox msgBox ;
    if (test)
      {  msgBox.setText("Ajout avec succes.") ;
     ui->Tab1->setModel(e.afficher()) ;
    ui->Tab_notif->setModel(n.afficher(id_test)) ;}

    else
        msgBox.setText("Echec d'ajout.") ;
    ui->Tab_notif->setModel(n.afficher(id_test)) ;
    msgBox.exec() ;
     ui->Tab_notif->setModel(n.afficher(id_test)) ;
}


void MainWindow::on_imprimer_clicked()
{
    QPrinter printer;
                  QPrintDialog *printDialog = new QPrintDialog(&printer, this);
                  printDialog->setWindowTitle("Imprimer Document");
                  printDialog->exec();

                  QPropertyAnimation *animationimprimerp;
                  animationimprimerp = new QPropertyAnimation(ui->imprimer,"geometry");
                  animationimprimerp->setDuration(1000);
                  animationimprimerp->setStartValue(QRect(690,20,141,51));
                  animationimprimerp->setEndValue(QRect(680,20,200,51));
                  animationimprimerp->setEasingCurve(QEasingCurve::InOutQuint);
                  animationimprimerp->start(QPropertyAnimation::DeleteWhenStopped);
}

void MainWindow::on_radioButton_clicked()
{
      ui->Tab1->setModel(e.triref()) ;
}

void MainWindow::on_radioButton_2_clicked()
{
     ui->Tab1->setModel(e.trinom()) ;
}

void MainWindow::on_radioButton_3_clicked()
{
     ui->Tab1->setModel(e.triprenom()) ;
}

void MainWindow::on_pushButton_4_clicked()
{
    int tabeq=ui->Tab_notif->currentIndex().row();
    //QString tabeq1=QString::number(tabeq);
                  //QVariant numm=ui->Tab_notif->model()->data(ui->Tab_notif->model()->index(tabeq,0));
                  //QString num= numm.toString();
                  int num_test=tabeq+1 ;
                   QString num_test1=QString::number(num_test);

                  QSqlQuery qry;
                  qry.prepare("select emetteur_id , body from notification where num=:numm");
                  qry.bindValue(":numm",num_test1);
                    qry.exec();
                    qry.first() ;
                  QSqlQuery qry1;
                  qry1.prepare("select * from employes where id=:id");
                  qry1.bindValue(":id",qry.value(0).toString());
                  qry1.exec();
                     QString  e_id , nom , prenom , e_mail , specialite ,  experience , grade , body   ;
                     qry1.first();
                      e_id=qry1.value(0).toString();
                      nom= qry1.value(1).toString();
                      prenom=qry1.value(2).toString();
                      e_mail=qry1.value(3).toString();
                      specialite=qry1.value(4).toString();
                      experience=qry1.value(5).toString();
                      grade=qry1.value(6).toString();


                     ui->notif_id->setText(e_id);
                     ui->notif_nom->setText(nom);
                     ui->notif_prenom->setText(prenom);
                     ui->notif_e_mail->setText(e_mail);
                     ui->notif_specialite->setText(specialite);
                     ui->notif_experience->setText(experience);
                     ui->notif_grade->setText(grade);

 ui->notif_body->setText(qry.value(1).toString()) ;

          //affichage de body

                     /*QSqlQuery query;
                          QString res ;
                            query.prepare("SELECT body from notification where RECEPTEUR like '%"+id_test+"%'") ;
                           // query.bindValue(":id_test",id_test);

                            query.exec();

                            query.first();

                             res= query.value(0).toString();*/
}

void MainWindow::on_supp_notif_clicked()
{
    int tabeq=ui->Tab_notif->currentIndex().row();
    QString tabeq1=QString::number(tabeq);
                  //QVariant num=ui->Tab_notif->model()->data(ui->Tab_notif->model()->index(tabeq,0));
                 // QString num1= num.toString();
                  QSqlQuery qry;
                   QSqlQuery qry2 ;
                  qry.prepare("DELETE from notification where num=:num1 ");
                  qry.bindValue(0,tabeq1);
                  bool test=qry.exec();
                  QMessageBox msgBox ;
                  if (test)
                    {  msgBox.setText("Suppression avec succes.") ;
                    ui->Tab_notif->setModel(n.afficher(id_test)) ; }
                  else
                      msgBox.setText("Echec de suppression.") ;
                  msgBox.exec() ;
                  int num2 = tabeq1.toInt() ;
                  num2=num2+1 ;
                   QString num3=QString::number(num2);
                  ui->Tab_notif->setModel(n.afficher(id_test)) ;
                  //ui->notif_body->setText(num3) ;
                  qry2.prepare("update notification set num=num-1 where num>=:num3 ");
                  qry2.bindValue(":num3",num3);
                  qry2.exec() ;
                  /* QSqlQuery query;
                   QString res ;
                     query.prepare("SELECT emetteur_id from notification where RECEPTEUR like '%"+id_test+"%'") ;
                    // query.bindValue(":id_test",id_test);

                     query.exec();

                     query.first();

                      res= query.value(0).toString();*/
}


/*void MainWindow::test()
{
    modifier m5 ;
    int test ;
    test=m5.valeur() ;
     QString test5=QString::number(test);
     ui->id_space->setText(test5) ;
}*/

void MainWindow::on_pushButton_6_clicked()
{ QSqlQuery query;
    query.prepare("DELETE from notification") ;
    query.exec() ;
    ui->Tab_notif->setModel(n.afficher(id_test)) ;
}



void MainWindow::on_ouvrir_chat_clicked()
{
    int tabeq=ui->chat_liste->currentIndex().row();
                  QVariant id=ui->chat_liste->model()->data(ui->chat_liste->model()->index(tabeq,0));
                  QVariant prenom=ui->chat_liste->model()->data(ui->chat_liste->model()->index(tabeq,2));
                     prenom1 = prenom.toString();
                 QString id1= id.toString();
                 r_chat=id1.toInt() ;
                 QString id_test1=QString::number(id_test);
                    QString r_chat1=QString::number(r_chat);
                  QSqlQuery qry;
                  qry.prepare("SELECT num , emetteur_id , body from chat where (emetteur_id=:r_chat OR emetteur_id=:id_test ) AND (recepteur=:r_chat OR recepteur=:id_test )");

                  qry.bindValue(":id_test",id_test1);
                  qry.bindValue(":r_chat",r_chat1);
                  qry.exec() ;
                   qry.first() ;
                 QString msg="" ;
                 if (qry.first()!=NULL)
                 {
                     while (qry.value(0).toString()!=NULL)
                     {
                         if (qry.value(1).toString()==id_test1)
                         { msg= msg+"vous :   "+qry.value(2).toString()+"\r\r" ;
                    qry.next() ; }
                         else {
                             msg=msg +prenom1 +" :   " +qry.value(2).toString()+"\r\r" ;
                                                 qry.next() ;
                         }

                        } }
                  ui->chat_prive->setText(msg) ;

}

void MainWindow::on_envoye_prive_clicked()
{ int o ;
    QSqlQuery qry1;
    qry1.prepare("select * from chat order by num");
    qry1.exec();

    if(qry1.first()==NULL)

    {
        o=1 ;

    }
    else {
       qry1.last();
       o=qry1.value(0).toInt()+1;
    }

    QString msg_envoye=ui->msg_prive->text();
    if (msg_envoye!=NULL)
    {
notification message (o , id_test , msg_envoye ,  "prive"  , r_chat) ;
bool test=message.ajouter_msg() ;
QString id_test1=QString::number(id_test);
   QString r_chat1=QString::number(r_chat);
 QSqlQuery qry;
 qry.prepare("SELECT num , emetteur_id , body from chat where (emetteur_id=:r_chat OR emetteur_id=:id_test ) AND (recepteur=:r_chat OR recepteur=:id_test ) order by num");

 qry.bindValue(":id_test",id_test1);
 qry.bindValue(":r_chat",r_chat1);
 qry.exec() ;
  qry.first() ;
QString msg="" ;
if (qry.first()!=NULL)
{
    while (qry.value(0).toString()!=NULL)
    {
        if (qry.value(1).toString()==id_test1)
        { msg= msg+"vous :   "+qry.value(2).toString()+"\r\r" ;
   qry.next() ; }
        else {
            msg=msg +prenom1 +" :   " +qry.value(2).toString()+"\r\r" ;
                                qry.next() ;
        }

       } }
 ui->chat_prive->setText(msg) ;

ui->msg_prive->setText("") ;
    }
}

void MainWindow::on_envoye_public_clicked()
{
    QString id_test1=QString::number(id_test);
    int o ;
       QSqlQuery qry1;
       qry1.prepare("select * from chat order by num");
       qry1.exec();

       if(qry1.first()==NULL)

       {
           o=1 ;

       }
       else {
          qry1.last();
          o=qry1.value(0).toInt()+1;
       }

       QString msg_envoye=ui->msg_public->text();
       if (msg_envoye!=NULL)
       {
   notification message (o , id_test , msg_envoye ,  "public"  , r_chat) ;
   bool test=message.ajouter_msg() ;

   QSqlQuery qry;
   QString titre_p="public" ;
   qry.prepare("SELECT num , emetteur_id , body from chat where titre=:titre order by num");

   qry.bindValue(":titre", titre_p);

   qry.exec() ;
    qry.first() ;
  QString msg="" ;
  if (qry.first()!=NULL)
  {
      while (qry.value(0).toString()!=NULL)
      {
          if (qry.value(1).toString()==id_test1)
          { msg= msg+"vous :   "+qry.value(2).toString()+"\r\r" ;
     qry.next() ; }
          else {
              QSqlQuery query2;
              query2.prepare("SELECT prenom from employes where id=:idd") ;
       query2.bindValue(":idd",qry.value(1).toString());
              query2.exec();
              query2.first() ;
              msg=msg +query2.value(0).toString()+ " :   "+qry.value(2).toString()+"\r\r" ;
                                  qry.next() ;
          }

         } }

    ui->chat_public->setText(msg) ;

   ui->msg_public->setText("") ;
       }
}

void MainWindow::on_fiche_confirmer_clicked()
{
    QString id_string= ui->fiche_id->text() ;
    QSqlQuery qry , query2 ;
    query2.prepare("update fiche_de_paie set employe_id=NULL where employe_id=:id_1 ");
     query2.bindValue(":id_1",id_string);
     query2.exec() ;
    qry.prepare("SELECT id from employes where id=:id");

    qry.bindValue(":id", id_string );

    qry.exec() ;
     qry.first() ;
     QMessageBox msgBox , msgBox1  ;

    if (qry.first()!=NULL)
    {
        QSqlQuery query;
        QString id_string= ui->fiche_id->text() ;
             query.prepare("INSERT INTO fiche_de_paie  ( salaire_brut , sante , impot_revenu , net_payer , employe_id  , fiche_date , date_1 , date_2)"
                           "VALUES (:salaire_brut , :sante , :impot_revenu , :net_payer , :employe_id , :fiche_date ,  :date_1 , :date_2)");
             query.bindValue(":employe_id",id_string);
             query.bindValue(":sante",ui->fiche_sante->text());
              query.bindValue(":impot_revenu",ui->fiche_impot->text());
               query.bindValue(":net_payer",ui->fiche_net->text());
            query.bindValue(":salaire_brut",ui->fiche_salaire->text());
            query.bindValue(":fiche_date",ui->fiche_date->text());
            query.bindValue(":date_1",ui->fiche_date_1->text());
            query.bindValue(":date_2",ui->fiche_date_2->text());

             bool test=query.exec() ;
             if (test)
             {
                   msgBox.setText("Fiche de paie affectée .") ;
             }
             else
             {
                 msgBox.setText("Erreur d'affectation de fiche de paie .") ;
             }
             msgBox.exec();
    }
    else {

      msgBox1.setText("Aucun employe avec cet identifiant !") ;
       msgBox1.exec();
}


}

void MainWindow::on_pushButton_5_clicked()
{
    QPrinter printer;
                  QPrintDialog *printDialog = new QPrintDialog(&printer, this);
                  printDialog->setWindowTitle("Imprimer Document");
                  printDialog->exec();

                  QPropertyAnimation *animationimprimerp;
                  animationimprimerp = new QPropertyAnimation(ui->imprimer,"geometry");
                  animationimprimerp->setDuration(1000);
                  animationimprimerp->setStartValue(QRect(690,20,141,51));
                  animationimprimerp->setEndValue(QRect(680,20,200,51));
                  animationimprimerp->setEasingCurve(QEasingCurve::InOutQuint);
                  animationimprimerp->start(QPropertyAnimation::DeleteWhenStopped);
}

void MainWindow::on_pushButton_8_clicked()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                notifyIcon-> show ();
                notifyIcon-> showMessage ( " employe " , " employe PDF " , QSystemTrayIcon :: Information, 15000 );
                QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->Tab1->model()->rowCount();
                const int columnCount = ui->Tab1->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                    //  "<meta Content="Text/html; charset=Windows-1251">\n"

                     <<  QString("<title>%1</title>\n").arg("Title")
                      <<  "</head>\n"
                       <<"<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                      <<"<center> <H1>Fiche administratif</H1></br></br>Liste des employes </br></br><table border=1 cellspacing=0 cellpadding=2>\n";


                // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->Tab1->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->Tab1->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->Tab1->isColumnHidden(column)) {
    QString data = ui->Tab1->model()->data(ui->Tab1->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                        "</body>\n"
                        "</html>\n";
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
                QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
                printer->setOutputFormat(QPrinter::PdfFormat);
                printer->setPaperSize(QPrinter::A4);
                printer->setOutputFileName(fileName);

                QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(printer);

                QPrinter *p=new QPrinter();
                QPrintDialog dialog(p,this);
                if(dialog.exec()== QDialog::Rejected)
                {
                    return;
                }
}
