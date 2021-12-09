#ifndef MODIFIER_EMPLOYE_H
#define MODIFIER_EMPLOYE_H

#include <QDialog>

namespace Ui {
class modifier_employe;
}

class modifier_employe : public QDialog
{
    Q_OBJECT

public:
     int read(int v) {return v ; };
    explicit modifier_employe(QWidget *parent = nullptr);
    ~modifier_employe();

private slots: 
    void on_Ajouter_bouton_clicked();

private:
    Ui::modifier_employe *ui;
};

#endif // MODIFIER_EMPLOYE_H
