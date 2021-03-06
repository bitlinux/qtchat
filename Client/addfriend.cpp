#include "addfriend.h"
#include "ui_addfriend.h"
#include <QMessageBox>
#include "constant.h"


AddFriend::AddFriend(QWidget *parent, tcpsocket *m, QString myid) :
    QDialog(parent),
    ui(new Ui::AddFriend)
{
    ui->setupUi(this);
    myID = myid;
    m_tcpsocket = m;
    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage1(int &)));
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::on_aply_but_clicked()
{
    if(this->ui->id_input->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("ID can not be empty.");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->id_input->text()==myID)
    {
        QMessageBox::about(this, "ERROR", "Can not add yourself!");
        this->ui->id_input->setText("");
        return ;
    }
    send_addfriend_request();
}

void AddFriend::send_addfriend_request()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(ADD_FRIEND)<<myID.toInt()<<this->ui->id_input->text().toInt()<<this->ui->textEdit->toPlainText();
    m_tcpsocket->write(block);
}

void AddFriend::readmessage1(int &type)
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

        /*QByteArray block;
        QDataStream out(&block,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        out << int(NEW_NOTI_FRIEND) << myID.toInt() << this->ui->id_input->text().toInt();
        m_tcpsocket->write(block);*/

        this->close();
        break;
    }
    case SEND_REQUEST_FAIL:
    {
        qDebug() << "SEND_REQUEST_FAIL";
        QMessageBox::about(this,"ERROR","Fail to send request.");
        this->ui->id_input->setText("");
        break;
    }
    case FRIEND_EXIST:
    {
        qDebug() << "FRIEND_EXIST";
        QMessageBox::about(this,"ERROR","Fail to send request.");
        this->ui->id_input->setText("");
    }
    }
}
