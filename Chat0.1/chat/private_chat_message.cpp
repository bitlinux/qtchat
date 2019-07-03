#include "private_chat_message.h"
#include "ui_private_chat_message.h"
#include <QDebug>

private_chat_message::private_chat_message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::private_chat_message)
{
    ui->setupUi(this);
}

private_chat_message::~private_chat_message()
{
    delete ui;
}

void private_chat_message::on_close_clicked()
{
    this->close();
}

void private_chat_message::set_information(QVector<UserTalkinfo> tinfo)
{
    for(int i=0; i<tinfo.size();i++)
    {
        QString time = tinfo[i].send_time;
        QString strs = "              " + time + "\n" + QString::number(tinfo[i].send_id) + ":   ";
        strs += tinfo[i].message + "\n";
        this->ui->browser->append(strs);
    }
    qDebug() << "chat_message" << tinfo.size();
}
