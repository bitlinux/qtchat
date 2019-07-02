#ifndef PRIVATE_CHAT_H
#define PRIVATE_CHAT_H

#include <QWidget>
#include <QtNetwork>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
#include "private_chat_message.h"
#include "tcpsocket.h"
#include "constant.h"

namespace Ui {
class private_chat;
}

class private_chat : public QWidget
{
    Q_OBJECT

public:
    explicit private_chat(QWidget *parent = nullptr, tcpsocket *m = nullptr);
    ~private_chat();
    void set_information(QString mID, QString mName, QString oID, QString oName, QString oPhoto);

private slots:

    void on_records_clicked();

    void on_file_clicked();

    void on_send_clicked();

    void on_sendfile_clicked();

    void readmessage(int &);

    void readID(QString &);

private:
    Ui::private_chat *ui;
    private_chat_message chat_message;
    QString myID;
    QString myName;
    QString otherID;
    QString otherName;
    QString otherPhoto;
    QTcpSocket *tcpSocket;
    QString message;
    tcpsocket *m_tcpsocket;
    QVector<UserTalkinfo> userinfo;
};

#endif // PRIVATE_CHAT_H
