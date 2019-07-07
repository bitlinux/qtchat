#include "forget_one.h"
#include "ui_forget_one.h"
#include"tcpsocket.h"
#include"constant.h"
forget_one::forget_one(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forget_one)
{
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);
    ui->setupUi(this);
    m_tcpsocket=new tcpsocket(this);
    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage(int &)));
    connect(m_tcpsocket,SIGNAL(connected()),this,SLOT(send_request()));
}

forget_one::~forget_one()
{
    delete ui;
}

/*show the ID and questions*/
void forget_one::set_information(QString id, QString pro1, QString pro2)
{
    this->ui->ID->setText(id);
    this->ui->problem_1->setText(pro1);
    this->ui->problem_2->setText(pro2);
}

/*go to the next forget*/
void forget_one::on_next_clicked()
{
    if(this->ui->answer_1->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Answer one cannot be empty!");
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

void forget_one::send_request()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(CHECK_ANSWER)<<this->ui->ID->toPlainText().toInt()<<this->ui->answer_1->text()<<this->ui->answer_2->text();
    m_tcpsocket->write(block);
}

void forget_one::readmessage(int &type)
{
   if(m_tcpsocket==nullptr)
       return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    qDebug() << "forget_one_in";
    switch(type)
    {
        case CHECK_SUCCESS:
    {
        qDebug() << "CHECK_SUCCESS";
        forget.show();
        forget.set_ID(this->ui->ID->toPlainText());
        this->close();
        break;
    }
        case CHECK_FAIL:
    {
        qDebug() << "CHECK_FAIL";
        QMessageBox::about(this,"ERROR","The answers are not right.");
        this->ui->answer_1->clear();
        this->ui->answer_2->clear();
        this->ui->answer_1->setFocus();
        break;
    }
    }
    m_tcpsocket->close();
}
