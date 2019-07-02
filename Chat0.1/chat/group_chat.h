#ifndef GROUP_CHAT_H
#define GROUP_CHAT_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
#include "group_chat_message.h"
#include "add_group_member.h"

namespace Ui {
class group_chat;
}

class group_chat : public QWidget
{
    Q_OBJECT

public:
    explicit group_chat(QWidget *parent = nullptr);
    ~group_chat();
    void set_information(QString mID, QString mName, QString gID, QString gName, QString gPhoto);

private slots:
    void on_records_clicked();

    void on_file_clicked();

    void on_send_clicked();

    void on_addnew_clicked();

    void on_change_clicked();

    void on_sendfile_clicked();

private:
    Ui::group_chat *ui;
    group_chat_message chat_message;
    QString myID;
    QString myName;
    QString groupID;
    QString groupName;
    QString groupPhoto;
    add_group_member add_member;
};

#endif // GROUP_CHAT_H
