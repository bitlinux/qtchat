#include "editname.h"
#include "ui_editname.h"
#include"constant.h"
#include"tcpsocket.h"
#include"mainwindow.h"
#include<QMessageBox>

editName::editName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editName)
{
    ui->setupUi(this);
    m_tcpsocket=new tcpsocket(this);
    //m_id=MainWindow::myID;
    connect(m_tcpsocket,SIGNAL(readyRead()),this,SLOT(readmessage()));
}

editName::~editName()
{
    delete ui;
}


void editName::readmessage()
{
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);

    int type;
    in>>type;
    switch(type)
    {
        case CHANGE_REMARK_SUCCESS:
    {
        //这里还需要前端界面设计逻辑
        this->close();
        break;
    }
        case CHANGE_REMARK_FAIL:
    {
        QString err;
        in>>err;
        QMessageBox::about(this,"change name fail",err);
        this->close();
        break;
    }
    }
}

void editName::on_pushButton_clicked()
{
    if(this->ui->id_input->text().length()==0)
    {
        QMessageBox::about(this,"Warning","new name cannot be empty");
        return ;
    }
    if(!m_tcpsocket->isConnected())
    {
        m_tcpsocket->requestConnect();
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(CHANGE_REMARK)<<m_id<<this->ui->id_input->text();
    m_tcpsocket->write(block);
}
