#ifndef NOTICE_DIALOG_H
#define NOTICE_DIALOG_H

#include <QDialog>
#include "tcpsocket.h"

namespace Ui {
class notice_dialog;
}

class notice_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit notice_dialog(QWidget *parent = nullptr, tcpsocket *m = nullptr,QString myid="", QString otherid="", QString othername="", QString time="", QString message="");
    ~notice_dialog();

private slots:
    void on_ok_button_clicked();

    void on_ignore_button_clicked();

    void send_request();

    void readmessage(int &);

private:
    Ui::notice_dialog *ui;
    QString otherID;
    QString othername;
    QString myID;
    QString time;
    QString message;
    tcpsocket *m_tcpsocket;
    int m_kind;

};

#endif // NOTICE_DIALOG_H
