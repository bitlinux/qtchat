#include "forget_two.h"
#include "ui_forget_two.h"
#include"tcpsocket.h"
#include"constant.h"
forget_two::forget_two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forget_two)
{
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);
    ui->setupUi(this);
    m_tcpsocket=new tcpsocket(this);
    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage(int &)));
    connect(m_tcpsocket,SIGNAL(connected()),this,SLOT(send_request()));
}

forget_two::~forget_two()
{
    delete ui;
}

/*show the ID number*/
void forget_two::set_ID(QString id)
{
    this->ui->ID->setText(id);
    m_id=id;
}

/*reset password*/
void forget_two::on_reset_clicked()
{
    if(this->ui->password->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Password cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->again->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Please enter the password again!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->again->text() != this->ui->password->text())
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("The password entered twice must be the same!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(!m_tcpsocket->isConnected())
    {
        m_tcpsocket->requestConnect();
    }
    // send ID,password to server

}

void forget_two::send_request()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(CHANGE_PASSWORD)<<m_id.toInt()<<this->ui->password->text();
    m_tcpsocket->write(block);
}

void forget_two::readmessage(int &type)
{
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    qDebug() << "forget_two_in";
    switch(type)
    {
        case CHANGE_PWD_SUCCESS:
    {
        qDebug() << "CHANGE_PWD_SUCCESS";
        QMessageBox::about(this,"Success","Reset password success.");
        this->close();
        break;
    }
        case CHANGE_PWD_FAIL:
    {
        qDebug() << "CHANGE_PWD_FAIL";
        QMessageBox::about(this,"ERROR","Fail to reset password.");
        this->ui->password->clear();
        this->ui->again->clear();
        this->ui->password->setFocus();
        break;
    }
    }
    m_tcpsocket->close();
}
