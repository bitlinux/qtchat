#include "login.h"
#include "ui_login.h"
#include"tcpsocket.h"
#include"constant.h"
#include<QByteArray>
#include<QDataStream>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);
    ui->setupUi(this);
    QPixmap pix("../resources/logo.png");
    ui->talkphoto->resize(400,300);
    QPixmap logo =pix.scaled(ui->talkphoto->size(),Qt::KeepAspectRatio);
    ui->talkphoto->setPixmap(logo);
    m_tcpsocket=new tcpsocket(this);
    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage2(int &)));
    connect(m_tcpsocket,SIGNAL(connected()),this,SLOT(send_request()));
}

login::~login()
{
    delete ui;
}

/*go to register*/
void login::on_register_2_clicked()
{
    reg.show();
}

/*go to forget password*/
void login::on_forget_clicked()
{
    if(this->ui->ID->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Please input your ID to reset the password!");
        QMessageBox::about(this, title, information);
        return ;
    }
    //send ID to server, get two problems
    if(!m_tcpsocket->isConnected())
    {
        m_tcpsocket->requestConnect();
    }
    m_kind = FORGET_PASSWORD_PROBLEM;
}

void login::send_forget_request()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(FORGET_PASSWORD_PROBLEM)<<this->ui->ID->text().toInt();
    m_tcpsocket->write(block);
}

/*go to login*/
void login::on_login_2_clicked()
{
    if(this->ui->ID->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("ID cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->password->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Password cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(!m_tcpsocket->isConnected())
    {
        m_tcpsocket->requestConnect();
    }
    m_kind = LOGIN;
}

void login::send_login_request()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(LOGIN)<<this->ui->ID->text()<<this->ui->ID->text().toInt()<<this->ui->password->text();
    m_tcpsocket->write(block);
}

void login::send_request()
{
    switch(m_kind)
    {
        case LOGIN:
        {
            send_login_request();
            break;
        }

        case FORGET_PASSWORD_PROBLEM:
        {
            send_forget_request();
            break;
        }
    }
}

void login::readmessage2(int &type)
{
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    switch(type)
    {
        case FORGET_PASSWORD_PROBLEM_SUCCESS:
    {
        qDebug() << "FORGET_PASSWORD_PROBLEM_SUCCESS";
        QString problem1,problem2;
        in>>problem1>>problem2;
        forget.set_information(this->ui->ID->text(), problem1, problem2);
        forget.show();
        m_tcpsocket->close();
        break;
    }
        case FORGET_PASSWORD_PROBLEM_FAIL:
    {
        qDebug() << "FORGET_PASSWORD_PROBLEM_FAIL";
        QMessageBox::about(this, "ERROR", "The ID is not valid.");
        this->ui->ID->clear();
        this->ui->ID->setFocus();
        m_tcpsocket->close();
        break;
    }
        case LOGIN_SUCCESS:
    {
        qDebug() << "LOGIN_SUCCESS";
        in>>maininfo.myID>>maininfo.myname>>maininfo.friends>>maininfo.groups>>maininfo.notifications;
        mw=new MainWindow(nullptr, m_tcpsocket, maininfo);  //应该添加上其他的内容
        mw->show();
        this->hide();
        break;
    }
        case LOGIN_FAIL:
    {
        qDebug() << "LOGIN_FAIL";
        QMessageBox::about(this, "ERROR", "The ID or the password is not valid.");
        this->ui->ID->clear();
        this->ui->password->clear();
        this->ui->ID->setFocus();
        m_tcpsocket->close();
        break;
    }
    }
}
