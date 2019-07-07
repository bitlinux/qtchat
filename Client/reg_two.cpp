#include "reg_two.h"
#include "ui_reg_two.h"
#include"tcpsocket.h"
#include"constant.h"
#include"login.h"
#include<QByteArray>
reg_two::reg_two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reg_two)
{
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);
    ui->setupUi(this);
    m_tcpsocket=new tcpsocket(this);
    linksignal();
}

reg_two::~reg_two()
{
    delete ui;
}

void reg_two::linksignal()
{
    connect(m_tcpsocket, SIGNAL(send_type(int &)), this, SLOT(read_the_message(int &)));
    connect(m_tcpsocket,SIGNAL(connected()),this,SLOT(send_request()));

}

/*go to the forward register*/
void reg_two::on_back_clicked()
{
    emit Back();
    this->close();
}

/*register*/
void reg_two::on_register_2_clicked()
{
    if(this->ui->problem_1->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Problem one cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->answer_1->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Answer one cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->problem_2->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Problem two cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->answer_2->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Answer two cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(!m_tcpsocket->isConnected())
    {
        m_tcpsocket->requestConnect();
    }

}

void reg_two::send_request()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(REGISTER)<<nickname<<password<<this->ui->problem_1->text()<<this->ui->answer_1->text()<<this->ui->problem_2->text()<<this->ui->answer_2->text();
    m_tcpsocket->write(block);
}

void reg_two::read_the_message(int &type)
{
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    qDebug() << "reg_two_in";
    switch(type)
    {
    case REGISTER_SUCCESS:
    {
        qDebug() << "REGISTER_SUCCESS";
        QString ID;
        in>>ID;
        reg_success *reg_sus = new reg_success();
        reg_sus->show();
        reg_sus->set_ID(ID);
        this->close();
        break;
    }
    case REGISTER_FAIL:
    {
        qDebug() << "REGISTER_FAIL";
        QMessageBox::about(this,"Error", "Fail to register.");
        login *log=new login();
        log->show();
        this->close();
        break;
    }
    default:
        break;
    }
    //关闭此页面与服务器的socket连接
    m_tcpsocket->close();
}
