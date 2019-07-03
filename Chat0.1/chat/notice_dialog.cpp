#include "notice_dialog.h"
#include "ui_notice_dialog.h"
#include "constant.h"
#include <QMessageBox>

notice_dialog::notice_dialog(QWidget *parent, tcpsocket *m, QString myid, QString id, QString name, QString time, QString message) :
    QDialog(parent),
    ui(new Ui::notice_dialog)
{
    ui->setupUi(this);
    myID = myid;
    otherID = id;
    m_tcpsocket = m;
    this->ui->ID->setText(id);
    this->ui->name->setText(name);
    this->ui->time->setText(time);
    this->ui->textBrowser->setText(message);
    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage(int &)));
}

notice_dialog::~notice_dialog()
{
    delete ui;
}

void notice_dialog::on_ok_button_clicked()
{
    m_kind = AGREE_FRIEND;
    send_request();
    this->close();
}

void notice_dialog::on_ignore_button_clicked()
{
    m_kind = REFUSE_FRIEND;
    send_request();
    this->close();
}

void notice_dialog::send_request()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(m_kind)<<otherID.toInt()<<myID.toInt();
    m_tcpsocket->write(block);
}

void notice_dialog::readmessage(int &type)
{
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    switch(type)
    {
        case SEND_REQUEST_SUCCESS:
    {
        qDebug() << "SEND_REQUEST_SUCCESS";
        this->close();
        break;
    }
        case SEND_REQUEST_FAIL:
    {
        qDebug() << "SEND_REQUEST_FAIL";
        if (m_kind == AGREE_FRIEND)
            QMessageBox::about(this, "ERROR", "Fail to add friend.");
        else if(m_kind == REFUSE_FRIEND)
            QMessageBox::about(this, "ERROR", "Fail to refuse friend.");
        break;
    }
    }
}
