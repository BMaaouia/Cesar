#include "integration.h"
#include "ui_integration.h"
#include "spectateur.h"
#include "login.h"
#include"mailing.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QDate>
#include<QTextStream>
#include <QPrinter>

#include <QPrintDialog>
#include<QFileDialog>
#include <QDebug>
#include <QRegularExpression>
#include <QTime>
//****************************maaouia****************************************
#include "terrain.h"
#include <QMessageBox>
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

//******************************************HAITHEM******************************************************
#include "joueur.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QtCharts>

#include <QMediaPlaylist>
#include <QMediaPlayer>
//************************************************yuki******************************************************
#include "facture.h"
#include "QrCode.hpp"

#include "facture.h"
#include <QString>
#include <QSqlQuery>
#include <QHeaderView>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QApplication>
#include <QMessageBox>
#include <QtWidgets>
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
#include <QSqlQueryModel>
#include "QrCode.hpp"
using namespace qrcodegen;
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>


integration::integration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integration)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100,999,this));

    ui->tab_Spectateur->setModel(E.afficher());


    ui->le_id->setPlaceholderText("id ...");
    ui->le_nom->setPlaceholderText("Nom ...");
    ui->le_prenom->setPlaceholderText("Prenom ...");
    ui->le_email->setPlaceholderText("Email ...");
    ui-> recherche_spectateur->setPlaceholderText("recherche(nom ou prenom) ...");

     ui->le_id->setMaxLength(4);

     ui->tab_Spectateur->setSelectionBehavior(QAbstractItemView::SelectRows);
     ui->tab_Spectateur->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->tab_Spectateur->setSelectionBehavior(QAbstractItemView::SelectRows);
     ui->tab_Spectateur->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->tab_Spectateur->setModel(E.afficher());

           ui->sexespectateur->addItem("H");
           ui->sexespectateur->addItem("F");


             ui->NumSMS->setMaxLength(12);




       current_user="";

     //Regex (pour contrôle de saisie)

        mail_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
        cin_regex=QRegExp("[0-9]{8}$");
        chaine_regex=QRegExp("[a-zA-Z]{2,20}$");
        tel_regex=QRegExp("[0-9]{8}$");
        salaire_regex=QRegExp("[0-9]+$");
        horaire_regex=QRegExp("^([0-1]?[0-9]|2[0-3]):[0-5][0-9]$");


       initial_width=this->width()*1;
       initial_height=this->height()*0.9;

       login_width=this->width()*1;
      login_height=this->height()*0.9;

       QRect screenGeometry = QApplication::desktop()->screenGeometry();
       center_main_x=(screenGeometry.width()-initial_width) / 2;
       center_main_y=(screenGeometry.height()-initial_height) / 2;
       center_login_x=(screenGeometry.width()-login_width) / 2;
       center_login_y=(screenGeometry.height()-login_height) / 2;

     QPixmap pic("C:/Users/DELL/Documents/photo(MOI)/photo.png");


      // this->setFixedSize(login_width,login_height);


       //Forgotten password hyperlink
           ui->mdp_oublie_label->setText(tr("<a href=\"whatever\">Mot de passe oublié?</a>"));
           ui->mdp_oublie_label->setTextInteractionFlags(Qt::TextBrowserInteraction);

           ui->passwordLineEdit_login->setEchoMode(QLineEdit::Password);
           ui->passwordLineEdit_signup->setEchoMode(QLineEdit::Password);
           ui->confimerMotDePasseLineEdit_signup->setEchoMode(QLineEdit::Password);


           timerr=new QTimer(this) ;

           connect(timerr , SIGNAL(timeout()),this,SLOT(myfunctionn())) ;
           timerr->start(1000) ;

       //****************************maaouia********************************


       ui->tableView_maaouia_affiche->setModel(T.afficher());
       ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,8}"),NULL));
       ui->lineEdit_capacite->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,6}"),NULL));
       ui->lineEdit_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,10}"),NULL));
       ui->lineEdit_emplacement->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,10}"),NULL));
       const QModelIndex &index=ui->tableView_maaouia_affiche->selectionModel()->currentIndex();

//****************************************HAITHEM***********************************************
       ui->tab_joueur->setModel(Etmp.afficher());
   ui->le_id2->setValidator(new QIntValidator(0,99999999,this));

//******************************************yuki***************************************************

 ui->tabfc->setModel(tempf->AfficherFacture());


}

integration::~integration()
{
    delete ui;
}

void integration::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    QString sexe=ui->sexespectateur->currentText();
    QString date_naissance =ui->dateN_c->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    Spectateur E(id,sexe,date_naissance,nom,prenom,email);
    notif m("Spectateur","Spectateur Ajouté(e)");
    m.afficher();


    bool test=E.ajouter();
    QMessageBox msgBox;

    if (test)
       { msgBox.setText("Ajout avec succes.");
         ui->tab_Spectateur->setModel(E.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();


}

void integration::on_pb_supprimer_clicked()
{
    Spectateur E1;
    E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());

    QMessageBox msgBox;

    if (test)
        msgBox.setText("Suppression avec succes.");
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
        ui->tab_Spectateur->setModel(E1.afficher());
         notif m("Spectateur","Spectateur Supprimé(e)");
          m.afficher();
}

void integration::on_tabWidget_currentChanged(int index )
{
 ui->tab_Spectateur->setModel(E.afficher());
}

void integration::on_modif_clicked()
{
    int id=ui->le_id->text().toInt();
    QString sexe=ui->sexespectateur->currentText();
    QString date_naissance= ui->dateN_c->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();

QMessageBox msgBox;
    bool test=E.modifier(id,sexe,date_naissance,nom,prenom,email);
    if (test)
        msgBox.setText("modification avec succes.");
    else
        msgBox.setText("Echec de modification");
        msgBox.exec();
    ui->tab_Spectateur->setModel(E.afficher());
     notif m("Spectateur","Spectateur Modifié(e)");
      m.afficher();
}



void integration::on_recherche_spectateur_textChanged(const QString &arg1)
{
     ui->tab_Spectateur->setModel(E.recherche_Spectateur(ui->recherche_spectateur->text()));
}

void integration::on_check_nom_tri_clicked()
{
    ui->tab_Spectateur->setModel(E.tri_nom());
    notif m("Spectateur","Spectateur triié(e)");
     m.afficher();
}

void integration::on_check_date_tri_clicked()
{
    ui->tab_Spectateur->setModel(E.tridate_naissance());

}

void integration::on_check_id_tri_clicked()
{
  ui->tab_Spectateur->setModel(E.tri_id());

}


void integration::on_imprimer_Spectateur_clicked()
{   QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tab_Spectateur->model()->rowCount();
    const int columnCount = ui->tab_Spectateur->model()->columnCount();
                    QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"



                        "<center> <H1>Liste des Spectateurs "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                       if (!ui->tab_Spectateur->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_Spectateur->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_Spectateur->isColumnHidden(column)) {
                                QString data =ui->tab_Spectateur->model()->data(ui->tab_Spectateur->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table> </center>\n";
out << "<tr>\n"

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
        notif m("Spectateur","Fichier Imprimé(e)");

         m.afficher();
}

void integration::on_send_mail_clicked()
{

    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());
}



void integration::on_envoyersms_clicked()
{
   QNetworkAccessManager * manager = new QNetworkAccessManager(this);
        //QUrl url("https://A1eb3aec305edca5d4cb4b2ac034bb97e1481f27fdfa02.twilio.com/edca5d4cb4b2ac0/Messages.json");
        QUrl url("https://AC474c04e1eb3aec305edca5d4cb4b2ac0:b7e34bb97e19566b8979481f27fdfa02@api.twilio.com/2010-04-01/Accounts/AC474c04e1eb3aec305edca5d4cb4b2ac0/Messages.json");
         //connect("A1eb3aec305edca5d4cb4b2ac034bb97e1481f27fdfa02.twilio.com/edca5d4cb4b2ac0/Messages.json");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");//*******IMPORTANT*******upload***
        QUrlQuery params;
        params.addQueryItem("From", "+18772033164");//+21650308026
        params.addQueryItem("To",ui->NumSMS->text() );//+21696560126
        params.addQueryItem("Body", ui->message__sms->toPlainText());
       // params.addQueryItem("Body", "test");

       // this->connect (manager, SIGNAL(finished(QNetworkReply)),  SLOT(slotRequestFinished(QNetworkReply)) );
        QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
       //QObject::connect (manager, SIGNAL(finished(QNetworkReply*)),this,   SLOT(slotRequestFinished(QNetworkReply*)));****BIBLIO*****
        manager->post(request, params.query().toUtf8());
    }

void integration::replyFinished(QNetworkReply* reply)
{
    //QByteArray bts = rep->readAll();
    QByteArray buffer = reply->readAll();
    qDebug() << buffer;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer));
    QJsonObject jsonReply = jsonDoc.object();

    QJsonObject response = jsonReply["response"].toObject();
    QJsonArray  data     = jsonReply["data"].toArray();
    qDebug() << data;
    qDebug() << response;


}




void integration::on_signup_button_clicked()
{
     bool email_verif=mail_regex.exactMatch(ui->eMailLineEdit_signup->text());

        bool confirm_pwd=ui->confimerMotDePasseLineEdit_signup->text()==ui->passwordLineEdit_signup->text();

        if (log->sign_up(ui->usernameLineEdit_signup->text(),ui->passwordLineEdit_signup->text(),ui->eMailLineEdit_signup->text()) && confirm_pwd && email_verif)
        {
            ui->stackedWidget->setCurrentIndex(1);
            current_user=ui->usernameLineEdit_signup->text();

            ui->confimerMotDePasseLineEdit_signup->text().clear();
            ui->passwordLineEdit_signup->text().clear();
            ui->eMailLineEdit_signup->text().clear();
            ui->usernameLineEdit_signup->text().clear();
            this->setFixedSize(initial_width,initial_height);

            this->move(center_main_x, center_main_y);
            ui->eMailLineEdit_signup->setStyleSheet("color: black");

        }

        else
        {
            if (!email_verif)
                ui->eMailLineEdit_signup->setStyleSheet("color: red");
            if (!confirm_pwd)
                QMessageBox::warning(this,tr("Inscription"),tr("Les deux mots de passe ne sont pas identiques"));
        }

}

void integration::on_login_button_clicked()
{



    if (ui->passwordLabel->text()=="Code")
        {

            if (log->sign_in_code(ui->usernameLineEdit_login->text(),ui->passwordLineEdit_login->text()))
            {
                QString pref=log->fetch_preferences(ui->usernameLineEdit_login->text());

                qDebug()<< pref;

                current_user=ui->usernameLineEdit_login->text();
                ui->stackedWidget->setCurrentIndex(0);



                if (current_user=="aziz")
                    ui->stackedWidget_2->setCurrentIndex(0);
                else if (current_user=="maaouia")
                    ui->stackedWidget_2->setCurrentIndex(1);
                else if (current_user=="haithem")
                    ui->stackedWidget_2->setCurrentIndex(2);
                else if (current_user=="yuki")
                    ui->stackedWidget_2->setCurrentIndex(3);
                else if (current_user=="rayen")
                    ui->stackedWidget_2->setCurrentIndex(4);

                else
                    ui->stackedWidget->setCurrentIndex(0);


                ui->usernameLineEdit_login->clear();
                ui->passwordLineEdit_login->clear();
                this->setFixedSize(initial_width,initial_height);
                this->move(center_main_x, center_main_y);

                QPixmap outPixmap = QPixmap();
                outPixmap.loadFromData(log->fetch_image(current_user),"PNG");
                outPixmap = outPixmap.scaledToWidth(ui->image_pos->width(),Qt::SmoothTransformation);
                ui->image_pos->setPixmap(outPixmap.scaled(outPixmap.width(),outPixmap.height(),Qt::KeepAspectRatio));

                ui->uname_label->setText(current_user);

            }
            else
                QMessageBox::warning(this,tr("Connexion"),tr("Erreur de connexion"));
        }
        else if (ui->passwordLabel->text()=="Mot de Passe")
        {
            if (log->sign_in(ui->usernameLineEdit_login->text(),ui->passwordLineEdit_login->text()))
            {
                QString pref=log->fetch_preferences(ui->usernameLineEdit_login->text());

                qDebug()<< pref;

                current_user=ui->usernameLineEdit_login->text();
                ui->stackedWidget->setCurrentIndex(0);



                if (current_user=="aziz")
                    ui->stackedWidget_2->setCurrentIndex(0);
                else if (current_user=="maaouia")
                    ui->stackedWidget_2->setCurrentIndex(1);
                else if (current_user=="haithem")
                    ui->stackedWidget_2->setCurrentIndex(2);
                else if (current_user=="yuki")
                    ui->stackedWidget_2->setCurrentIndex(3);
                else if (current_user=="rayen")
                    ui->stackedWidget_2->setCurrentIndex(4);
                else

                    ui->stackedWidget->setCurrentIndex(6);
                ui->usernameLineEdit_login->clear();
                ui->passwordLineEdit_login->clear();
                this->setFixedSize(initial_width,initial_height);

                this->move(center_main_x, center_main_y);

                ui->uname_label->setText(current_user);

                QPixmap outPixmap = QPixmap();
                outPixmap.loadFromData(log->fetch_image(current_user),"JPG");
                outPixmap = outPixmap.scaledToWidth(ui->image_pos->width(),Qt::SmoothTransformation);
                ui->image_pos->setPixmap(outPixmap.scaled(outPixmap.width(),outPixmap.height(),Qt::KeepAspectRatio));
            }
            else
            {
                QMessageBox::warning(this,tr("Connexion"),tr("Erreur de connexion"));
                test=false;
            }

        }
}



void integration::on_logout_button_clicked()
{
    this->setFixedSize(login_width,login_height);
        this->move(center_login_x,center_login_y);
        ui->stackedWidget->setCurrentIndex(1);

}

void integration::on_mdp_oublie_label_linkActivated(const QString &)
{
    if (ui->usernameLineEdit_login->text()!="")
        {
            login login;
            QString code=login.code_generator();
            QString email=login.fetch_email(ui->usernameLineEdit_login->text());
            login.update_mpd_reset(ui->usernameLineEdit_login->text(),code);

            QMessageBox::information(this, tr("Mot de passe oublié"), tr("Un code de vérification a été envoyé à votre adresse e-mail."));


            ui->passwordLabel->setText("Code");

       //     Mailing * ml = new Mailing("MedAziz.ALLANI@esprit.tn", "201JMT3326", "smtp.gmail.com", 465);
        //    ml->sendMail("MedAziz.ALLANI@esprit.tn", email , "Mot de Passe oublié" ,code);



            ui->usernameLineEdit_login->text().clear();
            ui->passwordLineEdit_login->text().clear();

        }
}

void integration::on_ajouter_image_clicked()
{
    login login;
       login.ajouter_image(current_user);



       QPixmap outPixmap = QPixmap();
       outPixmap.loadFromData(log->fetch_image(current_user),"PNG");
       outPixmap = outPixmap.scaledToWidth(ui->image_pos->width(),Qt::SmoothTransformation);

       // ui->image_pos->setPixmap(outPixmap);

       ui->image_pos->setPixmap(outPixmap.scaled(outPixmap.width(),outPixmap.height(),Qt::KeepAspectRatio));
}



void integration::myfunctionn()
{
    QTime time = QTime::currentTime() ;
        QString time_text=time.toString("hh : mm : ss")  ;

        ui->label_date_time->setText(time_text) ;
        ui->label_date_time_2->setText(time_text) ;

}


//*********************************************maaouia**********************************************************



void integration::on_pushButton_ajout_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString emplacement=ui->lineEdit_emplacement->text();
    QString type=ui->comboBox_type->currentText();
    int capacite=ui->lineEdit_capacite->text().toInt();
    QString etat=ui->comboBox_etat->currentText();

   Terrain T(id,capacite,etat,nom,type,emplacement);

   bool test=T.ajouter();
   if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("Ajouter un terrain"),
                        QObject::tr("terrain ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tableView_maaouia_affiche->setModel(T.afficher());

       QString objet="AJOUT terrain";
       QString message=" Votre terrain a été ajouté avec succés" ;

       QFile file("C:/Users/Mega-PC/Desktop/New folder (2)/integration/logs.txt");
       if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
           return;
       QTextStream cout(&file);
       QString d_info = QDateTime::currentDateTime().toString();
       QString message2=d_info+" - Un terrain a été ajouté \n";
       cout << message2;

      readfile();
   }

       else {
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }

}


void integration::on_tableView_maaouia_affiche_currentChanged(int index)
{
    ui->tableView_maaouia_affiche->setModel(T.afficher());
    ui->comboBox_tr->clear();
    ui->comboBox_tr->addItems(T.recherche_t());
    readfile();

    ui->comboBox_r->clear();
    ui->comboBox_r->addItems(T.recherche_e());

}



void integration::on_pushButton_supprime_clicked()
{
    Terrain T1;
    T1.set_id(ui->tableView_maaouia_affiche->selectionModel()->currentIndex().data().toInt());
   //   T1.set_id(ui->tableView_maaouia_affiche->selectionModel()->Columns);
    bool test=T1.supprimer(T1.get_id());


    QMessageBox msgBox;

    if(test){

        msgBox.setText("Suppression avec succes.");
         ui->tableView_maaouia_affiche->setModel(T.afficher());
        QFile file("C:/Users/Mega-PC/Desktop/New folder (2)/integration/logs.txt");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;
        QTextStream cout(&file);
        QString d_info = QDateTime::currentDateTime().toString();
        QString message2=d_info+" - Un terrain a été supprimé \n";
       cout << message2;
        readfile();
    }else{
    msgBox.setText("Echec ");
    msgBox.exec();
}
ui->tableView_maaouia_affiche->setModel(T.afficher());

}

void integration::on_pushButton_modif_clicked()
{
    Terrain T1;
    ui->comboBox_tr->clear();
    ui->comboBox_tr->addItems(T1.recherche_t());
    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString emplacement=ui->lineEdit_emplacement->text();
    QString type=ui->comboBox_type->currentText();
    int capacite=ui->lineEdit_capacite->text().toInt();
    QString etat=ui->comboBox_etat->currentText();

    bool test=T1.modifier(id,capacite,etat,nom,type, emplacement);


    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie une vehicule"),
                          QObject::tr("vehicule modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_maaouia_affiche->setModel(T.afficher());

         QFile file("C:/Users/DELL/Documents/QT projects/integration/logs.txt");
         readfile();
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;
        QTextStream cout(&file);
        QString d_info = QDateTime::currentDateTime().toString();
        QString message2=d_info+" - Un terrain a été modifié \n";
        cout << message2;


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    ui->tableView_maaouia_affiche->setModel(T.afficher());

}

/*void integration::on_pushButton_tri_clicked()
{

    ui->tableView_maaouia_affiche->setModel(T.tri_t());

}*/


/*void integration::on_tableView_maaouia_affiche_clicked(const QModelIndex &index)
{
    //ui->tableView_maaouia_affiche->selectionModel()->isColumnSelected(0,index);
   // ui->tableView_maaouia_affiche->horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);
    ui->tableView_maaouia_affiche->horizontalHeader()->sortIndicatorSection();
    ui->tableView_maaouia_affiche->setSortingEnabled(true);
    ui->tableView_maaouia_affiche->setModel(T.tri_t());
}*/

/*void integration::onColumnSelected(const QModelIndex &index)
{
    ui->tableView_maaouia_affiche->setModel(T.tri_t());
    ui->tableView_maaouia_affiche->setModel(T.afficher());

}*/





void integration::on_pushButton_imprim_clicked()
{
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();

            QPropertyAnimation *animationimprimerp;
            animationimprimerp = new QPropertyAnimation(ui->pushButton_imprim,"geometry");
            animationimprimerp->setDuration(1000);

            animationimprimerp->setEasingCurve(QEasingCurve::InOutQuint);
            animationimprimerp->start(QPropertyAnimation::DeleteWhenStopped);
}

void integration::on_pushButton_pdf_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tableView_maaouia_affiche->model()->rowCount();
    const int columnCount = ui->tableView_maaouia_affiche->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - TERRAINS LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> Gestion de Terrains </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_maaouia_affiche->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_maaouia_affiche->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_maaouia_affiche->isColumnHidden(column)) {
                QString data =ui->tableView_maaouia_affiche->model()->data(ui->tableView_maaouia_affiche->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}





void integration::on_lineEdit_recherche_textEdited(const QString &arg1)
{
    Terrain a;
    ui->tableView_maaouia_affiche->setModel(T.rechercher_dynamique(arg1));

}

void integration::readfile(){
    QString filename="C:/Users/Mega-PC/Desktop/New folder (2)/integration/logs.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "File doesnt exist "<<filename;
    }else{
        qDebug() << filename<<" File exist...";
    }
    QString line;
    ui->histo->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->histo->setText(ui->histo->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }
    file.close();
}





void integration::on_pushButton_affecter_clicked()
{
    int id=ui->comboBox_tr->currentText().toInt();
    int ide=ui->comboBox_r->currentText().toInt();
    //int id=ui->comboBox_3->itemText();

    Terrain T1;
    bool test=T1.modifier_e(id,ide);


    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Afecter une terrain"),
                          QObject::tr("Terrain Affecte.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}}


//**********************************************HAITHEM*******************************************************
void integration::on_pushButton_6_clicked() // ajouter //
{
    int id=ui->le_id2->text().toInt ();
    int classement=ui->le_classement->text().toInt ();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString domainedesport=ui->le_domainedesport->text();
    QString nationalite=ui->la_nationalite->text();
    Joueur J (id,classement,nom,prenom,domainedesport,nationalite);

bool test=J.ajouter();
if (test)
        { //Actualiser
   ui->tab_joueur->setModel(Etmp.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}
void integration::on_pushButtonSupprimer_clicked()
{
    Joueur J;J.setid(ui->le_id->text().toInt());
        bool test=Etmp.supprimer(J.getid());
        QMessageBox msgBox;
        if (test)
                {
            //actualiser
          ui->tab_joueur->setModel(Etmp.afficher());
                QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                   QObject::tr("Suppression effectué\n"
                                                               "click cancel to exit."),QMessageBox::Cancel);
                }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                      QObject::tr("Suppression non effectué.\n"
                                                  "click Cancel to exit."),QMessageBox::Cancel);
}

void integration::on_PushButtonModifier_clicked()
{
    int id=ui->le_id2->text().toInt ();
    int classement=ui->le_classement->text().toInt ();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString domainedesport=ui->le_domainedesport->text();
    QString nationalite=ui->la_nationalite->text();
    Joueur J (id,classement,nom,prenom,domainedesport,nationalite);

    bool test=J.modifier(id,classement,nom,prenom,domainedesport,nationalite);
    if (test)
            { //Actualiser
         ui->tab_joueur->setModel(Etmp.afficher());
            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                               QObject::tr("modification effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("modification non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
}

void integration::on_recherche_clicked()
{
    QString rech =ui->le_id->text();
            ui->tab_joueur->setModel(Etmp.rechercher(rech));
}



void integration::on_tri_clicked()
{
    Joueur *c = new Joueur();
      ui->tab_joueur->setModel(c->tri());
}








void integration::on_imp_clicked()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
            notifyIcon-> show ();
            notifyIcon-> showMessage ( " Joueur " , " Joueur PDF " , QSystemTrayIcon :: Information, 15000 );
            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tab_joueur->model()->rowCount();
            const int columnCount = ui->tab_joueur->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                //  "<meta Content="Text/html; charset=Windows-1251">\n"

                 <<  QString("<title>%1</title>\n").arg("Title")
                  <<  "</head>\n"
                   <<"<body bgcolor=#ffffff link=#5000A0>\n"

                     //     "<align='right'> " << datefich << "</align>"
                  <<"<center> <H1>Responsable des Joueurs</H1></br></br>Liste des joueurs </br></br><table border=1 cellspacing=0 cellpadding=2>\n";


            // headers
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tab_joueur->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_joueur->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_joueur->isColumnHidden(column)) {
                        QString data = ui->tab_joueur->model()->data(ui->tab_joueur->model()->index(row, column)).toString().simplified();
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

void integration::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("select * from JOUEUR where CLASSEMENT > 2 ");
           int number1=model->rowCount();
           model->setQuery("select * from JOUEUR where CLASSEMENT < 3 ");
           int number2=model->rowCount();
           int total=number1+number2;
           QString a = QString("classement pour les joueurs plus que deuxeme place  "+QString::number((number1*100)/total,'f',2)+"%" );
           QString b = QString("classement pour les joueurs moins que deuxeme place  "+QString::number((number2*100)/total,'f',2)+"%" );

           QPieSeries *series = new QPieSeries();
           series->append(a,number1);
           series->append(b,number2);

           if (number1!= 0)
           {
               QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());
           }
           if (number2!=0)
           {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
           }

                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Pourcentage Par classement "+ QString::number(total));
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);
                   chartView->show();
}


//************menu*****************//


void integration::on_Joueur_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->tab_joueur->setModel(Etmp.afficher());
}

void integration::on_Terrain_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->tableView_maaouia_affiche->setModel(T.afficher());
    ui->tableView_maaouia_affiche->setModel(T.afficher());
    ui->comboBox_tr->clear();
    ui->comboBox_tr->addItems(T.recherche_t());
    readfile();

    ui->comboBox_r->clear();
    ui->comboBox_r->addItems(T.recherche_e());

    ui->comboBox_type->clear();
    ui->comboBox_type->addItems(T.recherche_s());

    ui->tableView_maaouia_affiche->setSortingEnabled(true); // enable sortingEnabled
    ui->tableView_maaouia_affiche->setModel(T.sort());
}

void integration::on_Spectateur_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->tab_Spectateur->setModel(E.afficher());
}





QMediaPlayer *music = new QMediaPlayer();
QMediaPlaylist *playlist = new QMediaPlaylist();
void integration::on_checkBox_clicked()
{
    //
    music->setMedia(QUrl("qrc:/res/bg.mp3"));
    playlist->addMedia(QUrl("qrc:/res/bg.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
     music->setPlaylist(playlist);


    if(ui->checkBox->isChecked()){
        music->play();
        }
    else if(ui->checkBox->isChecked()==false)   {
        music->stop();
    }
}










//********************************************************yuki***********************************************************

void integration::on_Ajout_client_clicked()
{
    int idfc =ui->lineEdit_id_3->text().toInt();
    QString client=ui->clientfc->currentText();
    QString type=ui->type_facture->currentText();
    QString date=ui->date_facture->text();
    Facture f(idfc,client,type,date);

    QString nom=ui->clientfc->currentText();
    f.modifier_e(nom);

    bool test=f.AjouterFacture();
    if (test)
        {
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        ui->tabfc->setModel(f.AfficherFacture());
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
    ui->tabfc->setModel(f.AfficherFacture());
    ui->tabfc->setSelectionBehavior(QAbstractItemView::SelectRows);
    QTableView * view = new QTableView();
    view->verticalHeader()->hide();
}

void integration::on_pushButton_materiel_clicked()
{
    int quantite =ui->lineEdit_quantite_materiel->text().toInt();
    int cout=ui->lineEdit_cout_materiel->text().toInt();
    QString nom=ui->lineEdit_nom_materiel->text();

    Materiel m(nom,quantite,cout);


    bool test=m.AjouterMateriel();
    if (test)
        {
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
       // ui->tabfc->setModel(f.AfficherFacture());


        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}

void integration::on_pushButton_sponsor_clicked()
{
    int argent =ui->lineEdit_argent->text().toInt();

    QString nom=ui->lineEdit_sponsor->text();

    sponsor m(nom,argent);

    bool test=m.AjouterSponsor();
    if (test)
        {
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
       // ui->tabfc->setModel(f.AfficherFacture());

        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}

void integration::on_type_facture_currentIndexChanged(const QString &arg1)
{
    if(ui->type_facture->currentText()=="Revenue"){
    ui->clientfc->clear();
    ui->clientfc->addItems(f.recherche_s());}
    else {
        ui->clientfc->clear();
        ui->clientfc->addItems(f.recherche_m());
    }
}





void integration::on_tri_2_clicked()
{
    QString choix = ui->comboBox_tri->currentText();
            if (choix =="ID" ){
                ui->tabfc->setModel(f.triID());
            }else if(choix=="client") {
                ui->tabfc->setModel(f.tri_client());
            }else{
                ui->tabfc->setModel(f.tri_pay());
            }
}

void integration::on_imprimer_clicked()

    {
        QPrinter printer;
                QPrintDialog *printDialog = new QPrintDialog(&printer, this);
                printDialog->setWindowTitle("Imprimer Document");
                printDialog->exec();

                QPropertyAnimation *animationimprimerp;
                animationimprimerp = new QPropertyAnimation(ui->imprimer,"geometry");
                animationimprimerp->setDuration(1000);

                animationimprimerp->start(QPropertyAnimation::DeleteWhenStopped);

}

void integration::on_lineEdit_textEdited(const QString &arg1)
{
    Facture a;
    ui->tabfc->setModel(a.rechercher_dynamique(arg1));
}

/*void integration::on_QRcode_clicked()
{

        int tabeq=ui->tabfc->currentIndex().row(); //selectionner le ligne
               QVariant idd=ui->tabfc->model()->data(ui->tabfc->model()->index(tabeq,0)); // selctionner la case
               QString id= idd.toString();
               QSqlQuery qry; // fournir les donnes
               qry.prepare("select * from CLIENT where CIN=:id");
               qry.bindValue(":CIN",id);
               qry.exec(); //execution
                  QString  iden,nom,adresse,nbreticket,destination,abonnement ,ide; //convertir les donnes en chaine du caractere

               while(qry.next()){

                   id=qry.value(1).toString();
                   nom=qry.value(2).toString();
                   adresse=qry.value(3).toString();
                   nbreticket=qry.value(4).toString();
                   destination=qry.value(5).toString();
                   abonnement=qry.value(6).toString();

               }
               ide=QString(id);
                      ide="CIN:"+ide+"ID:"+iden+"NOM:"+nom+"ADRESSE:"+adresse +"NBRE_TICKET:"+nbreticket+"DESTINATION:"+destination+"ABONNEMENT:"+abonnement; // importer les donnes depuis la base
               QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

               // Read the black & white pixels
               QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
               for (int y = 0; y < qr.getSize(); y++) {
                   for (int x = 0; x < qr.getSize(); x++) {
                       int color = qr.getModule(x, y);  // 0 for white, 1 for black

                       // You need to modify this part
                       if(color==0)
                           im.setPixel(x, y,qRgb(254, 254, 254));
                       else
                           im.setPixel(x, y,qRgb(0, 0, 0));
                   }
               }
               im=im.scaled(200,200); //size
               ui->qrcodecommande->setPixmap(QPixmap::fromImage(im)); //importation


}
*/



void integration::on_QRcode_clicked()
{
    int tabev=ui->tabfc->currentIndex().row();
    QVariant idd=ui->tabfc->model()->data(ui->tabfc->model()->index(tabev,0));
    QString id= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from FACTURE where IDFC=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString nom,debut,fin,idp,ids;
    while(qry.next()){
        nom=qry.value(0).toString();
        debut=qry.value(1).toString();
        fin=qry.value(2).toString();
        idp=qry.value(3).toString();
    }
    ids=QString(id);
    ids="0 : "+ids+"  1 : "+nom+" 2 : "+debut+" 3 : "+fin+" 4 : "+idp;
    QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->QRcode_2->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
}








void integration::on_budget_clicked()
{

        ui->tabfc->setModel(f.AfficherFacture());
        QSqlQuery query("select sum(ARGENT) from SPONSOR");
        QSqlQuery query1("select sum(COUT) from MATERIAUX");
            while (query.next()&& query1.next()) {
                int argent = query.value(0).toInt();
                int cout = query1.value(0).toInt();
                ui->budget_label->setText( QString::number(argent) );
                ui->budget_label_2->setText( QString::number(cout) );
                ui->budget_label_3->setText( QString::number(argent-cout) );
            }


   /*  int result = 0,result1=0;
         const int column = 4,col=5;
         for (int row = 0; row < ui->tabfc->model()->rowCount(); ++row) {
             if(ui->tabfc->model()->data(ui->tabfc->model()->index(row,2))=="Revenue"){
             result += ui->tabfc->model()->data(ui->tabfc->model()->index(row, column)).toInt();}
         }
         for (int row = 0; row < ui->tabfc->model()->rowCount(); ++row) {
             if(ui->tabfc->model()->data(ui->tabfc->model()->index(row,2))=="Depense"){
             result1 += ui->tabfc->model()->data(ui->tabfc->model()->index(row, col)).toInt();}
         }
         ui->budget_label->setText( QString::number(result) );
         ui->budget_label_2->setText( QString::number(result1) );
         ui->budget_label_3->setText( QString::number(result-result1) );*/

}

void integration::on_stat_facture_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           QSqlQuery query("select sum(ARGENT) from SPONSOR");
            QSqlQuery query1("select sum(COUT) from MATERIAUX");
           while (query.next()&& query1.next()) {
               int number1 = query.value(0).toInt();

           int number2=query1.value(0).toInt();
           int total=number1+number2;
           int budget=number1-number2;
           QString a = QString("Revenue"+QString::number((number1*100)/total,'f',2)+"%" );
           QString b = QString("Depense"+QString::number((number2*100)/total,'f',2)+"%" );

           QPieSeries *series = new QPieSeries();
           series->append(a,number1);
           series->append(b,number2);

           if (number1!= 0)
           {
               QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());
           }
           if (number2!=0)
           {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
           }

                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Budget = "+ QString::number(budget)+" DT");
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);
                   chartView->show();
           }
}



void integration::on_modifier_client_clicked()
{
    QString client=ui->clientfc->currentText();
    QString type=ui->type_facture->currentText();
    QString date=ui->date_facture->text();
    QItemSelectionModel *select = ui->tabfc->selectionModel();
    int idfc = ui->lineEdit_id_3->text().toInt();
QMessageBox msgBox;

    bool test=f.ModifierFacture(idfc,client,type,date);
    if (test)
        msgBox.setText("modification avec succes.");
    else
        msgBox.setText("Echec de modification");
        msgBox.exec();
    ui->tabfc->setModel(f.AfficherFacture());


}


void integration::on_supprimer_client_clicked()
{
    QMessageBox msg;
    QString client=ui->clientfc->currentText();
    QString type=ui->type_facture->currentText();
    QString date=ui->date_facture->text();
    QItemSelectionModel *select = ui->tabfc->selectionModel();

    if (!select->hasSelection()){
         msg.setText("selectionner une facture a supprimer");
         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString idfc=select->selectedRows().at(0).data().toString();

    int id = QString (idfc).toInt();
    Facture f(id,client,type,date);
    bool test=f.SupprimerFacture(id);
    if (test)
        {
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Suppression effectuée avec succès\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("suppression non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
    ui->tabfc->setModel(f.AfficherFacture());
    ui->tabfc->setSelectionBehavior(QAbstractItemView::SelectRows);
    QTableView * view = new QTableView();
    view->verticalHeader()->hide();
}
