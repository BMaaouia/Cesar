#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "spectateur.h"
#include"smtp.h"
#include "notif.h"
#include "login.h"
#include"mailing.h"

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QNetworkReply>
#include <QNetworkRequest>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

//************************************maaouia*******************************************
#include "terrain.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QString>

//**************************************HAITHEM***************************************************
#include "joueur.h"
//****************************************yuki*************************************************
#include "facture.h"
#include "materiel.h"
#include "sponsor.h"
#include "QrCode.hpp"
#include <QtWidgets>
#include <QPdfWriter>
#include <QProcess>






namespace Ui {
class integration;
}

class integration : public QMainWindow
{
    Q_OBJECT

public:
    explicit integration(QWidget *parent = nullptr);
    ~integration();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_modif_clicked();

    void on_recherche_spectateur_textChanged(const QString &arg1);

    void on_check_id_tri_clicked();

    void on_check_date_tri_clicked();

    void on_check_nom_tri_clicked();

     void on_imprimer_Spectateur_clicked();

     void on_send_mail_clicked();

   //  void mailSent(QString);




     void on_envoyersms_clicked();

      void replyFinished(QNetworkReply* reply);



      void on_signup_button_clicked();

      void on_login_button_clicked();

      void on_logout_button_clicked();

      void on_mdp_oublie_label_linkActivated(const QString &link);

      void on_ajouter_image_clicked();

      void myfunctionn();


//***************************maaouia****************************************

      void on_pushButton_ajout_clicked();

      void on_tableView_maaouia_affiche_currentChanged(int index);



      void on_pushButton_supprime_clicked();

      void on_pushButton_modif_clicked();

      void on_pushButton_imprim_clicked();

      void on_pushButton_pdf_clicked();

      void on_lineEdit_recherche_textEdited(const QString &arg1);

      void readfile();



      void on_pushButton_affecter_clicked();
      void on_checkBox_clicked();



//*******************************************HAITHEM***************************************************************
      void on_pushButton_6_clicked();

      void on_pushButtonSupprimer_clicked();

      void on_PushButtonModifier_clicked();

      void on_recherche_clicked();

      void on_tri_clicked();

      void on_imp_clicked();

      void on_stat_clicked();
//********************************************************yuki****************************************************************

  void on_Ajout_client_clicked();



  void on_tri_2_clicked();

  void on_imprimer_clicked();

  void on_lineEdit_textEdited(const QString &arg1);

  void on_QRcode_clicked();

  void on_pushButton_materiel_clicked();

  void on_pushButton_sponsor_clicked();

  void on_type_facture_currentIndexChanged(const QString &arg1);

  void on_budget_clicked();

  void on_stat_facture_clicked();

  void on_modifier_client_clicked();

  void on_supprimer_client_clicked();


 //****************************************************************************************************



  void on_Spectateur_clicked();

  void on_Terrain_clicked();

  void on_Joueur_clicked();




private:
    Ui::integration *ui;
    Spectateur E;

      QRegExp cin_regex,chaine_regex,tel_regex,mail_regex,salaire_regex,horaire_regex ;
      login *log;

      QString current_user;

      int initial_width;
      int initial_height;

      int login_width;
      int login_height;

      int center_main_x=0;
      int center_main_y=0;
      int center_login_x=0;
      int center_login_y=0;
       bool test=false;

         QTimer *timerr;
//***********************maaouia******************************
      Terrain T;
//***********************HAITHEM****************************
      Joueur Etmp;
 //*************yuki************************
     Facture *tempf,f;
     Materiel m;
     sponsor s;
};
#endif // INTEGRATION_H
