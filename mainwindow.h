#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Spectateur.h"
#include"smtp.h"
#include "notif.h"

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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

     void mailSent(QString);




     void on_envoyersms_clicked();

      void replyFinished(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    Spectateur E;
      QRegExp le_email_regex ;
};

#endif // MAINWINDOW_H
