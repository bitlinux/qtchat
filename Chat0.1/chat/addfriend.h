#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QDialog>
#include "tcpsocket.h"


namespace Ui {
class AddFriend;
}

class AddFriend : public QDialog
{
    Q_OBJECT

public:
    explicit AddFriend(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString myid="");
    ~AddFriend();
    void set_value(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString myid=""){m_tcpsocket=m;myID=myid;}


private slots:
    void on_aply_but_clicked();

    void send_addfriend_request();

    void readmessage1(int &type);


private:
    Ui::AddFriend *ui;
    QString myID;
    tcpsocket *m_tcpsocket;
};

#endif // ADDFRIEND_H
