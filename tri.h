#ifndef TRI_H
#define TRI_H

#include <QDialog>

namespace Ui {
class tri;
}

class tri : public QDialog
{
    Q_OBJECT

public:
    explicit tri(QWidget *parent = nullptr);
    ~tri();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tri *ui;
};

#endif // TRI_H
