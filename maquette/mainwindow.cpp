#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
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
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_joueur->setModel(Etmp.afficher());
ui->le_id2->setValidator(new QIntValidator(0,99999999,this));
ui->le_classement->setValidator(new QIntValidator(0,99999999,this));

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_6_clicked() // ajouter //
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
void MainWindow::on_pushButtonSupprimer_clicked()
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

void MainWindow::on_PushButtonModifier_clicked()
{
    int id=ui->le_id3->text().toInt ();
    int classement=ui->classement_m->text().toInt ();
    QString nom=ui->nom_m->text();
    QString prenom=ui->prenom_m->text();
    QString domainedesport=ui->domaine_m->text();
    QString nationalite=ui->nationalite_m->text();
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

void MainWindow::on_recherche_clicked()
{
    QString rech =ui->le_id->text();
            ui->tab_joueur->setModel(Etmp.rechercher(rech));
}



void MainWindow::on_tri_clicked()
{
    Joueur *c = new Joueur();
      ui->tab_joueur->setModel(c->tri());
}








void MainWindow::on_imp_clicked()
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

void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("select * from GESTIONJOUEUR where CLASSEMENT > 2 ");
           int number1=model->rowCount();
           model->setQuery("select * from GESTIONJOUEUR where CLASSEMENT < 3 ");
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
