#include "facture.h"
Facture::Facture()
{
    idfc=0;
    client="";
    type="";
    date="";
}
Facture::Facture(int idfc, QString client,QString type,QString date)
{
    this->idfc=idfc;
    this->client=client;
    this->type=type;
    this->date=date;
}
bool Facture::AjouterFacture()
{
QSqlQuery query;
QString res1= QString::number(idfc);
query.prepare("insert into FACTURE (IDFC,CLIENTFC,TYPE,DATEC)" "values(:idfc, :client,:type, :date)");
query.bindValue(":client",client);
query.bindValue(":type",type);
query.bindValue(":date",date);
query.bindValue(":idfc",res1);
return query.exec();

}
QSqlQueryModel* Facture:: AfficherFacture()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM FACTURE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type de paiement"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
         return model;

 }



bool Facture::ModifierFacture(int idfc,QString client,QString type,QString date)
{
    QSqlQuery query;
    query.prepare("UPDATE FACTURE SET IDFC=:idfc,CLIENTFC=:client, type=:type, datec=:date WHERE IDFC=:idfc");
    query.bindValue(":idfc",idfc);
    query.bindValue(":client",client);
    query.bindValue(":type",type);
    query.bindValue(":date",date);
    return query.exec();
}

bool Facture::SupprimerFacture(int Num)
 {
     QSqlQuery query;

     query.prepare("DELETE FROM FACTURE WHERE IDFC=:idfc");
     query.bindValue(":idfc",Num);

     return query.exec();
 }


QSqlQueryModel * Facture::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FACTURE order by IDFC");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * Facture::tri_client()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FACTURE order by CLIENTFC");
    return model;
}

QSqlQueryModel * Facture::tri_pay()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FACTURE order by type");
    return model;
}


QSqlQueryModel * Facture::rechercher_dynamique(QString a)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM FACTURE WHERE CLIENTFC like '%"+a+"%'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    return model;
}

QStringList Facture::recherche_m(){
    QSqlQuery query;
    query.prepare("select NOM_M  from MATERIAUX   ");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}

QStringList Facture::recherche_s(){
    QSqlQuery query;
    query.prepare("select  NOM from  SPONSOR  ");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}


bool Facture::modifier_e(QString nom)
{
    QSqlQuery query;

    query.prepare("UPDATE FACTURE SET SPONSOR='YES'  WHERE CLIENTFC=:nom ");

    query.bindValue(":CLIENTFC", nom);

    return    query.exec();

}




/*QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from CLIENT where DESTINATION='Rades' ");
     int number1=model->rowCount();
     model->setQuery("select * from CLIENT where DESTINATION='Ezzahra' ");
     int number2=model->rowCount();
     model->setQuery("select * from CLIENT where DESTINATION='Hammem lif' ");
     int number3=model->rowCount(); // calculer le nombre de voyage pour hammem lif
     model->setQuery("select * from CLIENT where DESTINATION='Autre' ");
     int number4=model->rowCount();
     int date=number1+number2+number3+number4;
     QString a = QString("rades  "+QString::number((number1*100)/date,'f',2)+"%" );
     QString b = QString("ezzahra "+QString::number((number2*100)/date,'f',2)+"%" );
     QString c = QString("hammem lif "+QString::number((number3*100)/date,'f',2)+"%" );
     QString d = QString("autre "+QString::number((number4*100)/date,'f',2)+"%" );
     QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
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
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("pourcentage sur les destinations "+ QString::number(date));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();
*/
