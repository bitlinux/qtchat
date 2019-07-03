#ifndef EDITNAME_H
#define EDITNAME_H

#include <QDialog>
class tcpsocket;

namespace Ui {
class editName;
}

class editName : public QDialog
{
    Q_OBJECT

public:
    explicit editName(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString myid = "");
    ~editName();

private slots:

    void on_pushButton_clicked();

private:
    Ui::editName *ui;
    tcpsocket *m_tcpsocket;
    QString myID;
};

#endif // EDITNAME_H
