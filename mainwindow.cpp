#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Spectateur.h"
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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
           ui->sexespectateur_3->addItem("H");
           ui->sexespectateur_3->addItem("F");

             ui->NumSMS->setMaxLength(12);


       le_email_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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

void MainWindow::on_tabWidget_currentChanged(int index )
{
 ui->tab_Spectateur->setModel(E.afficher());
}

void MainWindow::on_modif_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString sexe=ui->sexespectateur_3->currentText();
    QString date_naissance= ui->dateN_c->text();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString email=ui->le_email_2->text();

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



void MainWindow::on_recherche_spectateur_textChanged(const QString &arg1)
{
     ui->tab_Spectateur->setModel(E.recherche_Spectateur(ui->recherche_spectateur->text()));
}

void MainWindow::on_check_nom_tri_clicked()
{
    ui->tab_Spectateur->setModel(E.tri_nom());
    notif m("Spectateur","Spectateur triié(e)");
     m.afficher();
}

void MainWindow::on_check_date_tri_clicked()
{
    ui->tab_Spectateur->setModel(E.tridate_naissance());

}

void MainWindow::on_check_id_tri_clicked()
{
  ui->tab_Spectateur->setModel(E.tri_id());

}


void MainWindow::on_imprimer_Spectateur_clicked()
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

void MainWindow::on_send_mail_clicked()
{

    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());
}



void MainWindow::on_envoyersms_clicked()
{

   QNetworkAccessManager * manager = new QNetworkAccessManager(this);

        QUrl url("https://AC474c04e1eb3aec305edca5d4cb4b2ac0:b7e34bb97e19566b8979481f27fdfa02@api.twilio.com/2010-04-01/Accounts/AC474c04e1eb3aec305edca5d4cb4b2ac0/Messages.json");
        QNetworkRequest request(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");


        QUrlQuery params;
        params.addQueryItem("From", "+18772033164");
        params.addQueryItem("To",ui->NumSMS->text() );//96560126
        params.addQueryItem("Body", ui->message__sms->toPlainText());
       // params.addQueryItem("Body", "test");

        // etc

        QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));

        manager->post(request, params.query().toUtf8());

    }

void MainWindow::replyFinished(QNetworkReply* reply)
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

