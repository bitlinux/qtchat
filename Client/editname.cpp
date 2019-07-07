#include "editname.h"
#include "ui_editname.h"
#include"constant.h"
#include"tcpsocket.h"
#include"mainwindow.h"
#include<QMessageBox>

editName::editName(QWidget *parent, tcpsocket *m, QString myid) :
    QDialog(parent),
    ui(new Ui::editName)
{
    ui->setupUi(this);
    m_tcpsocket = m;
    myID = myid;
}

editName::~editName()
{
    delete ui;
}

void editName::on_pushButton_clicked()
{
    if(this->ui->id_input->text().length()==0)
    {
        QMessageBox::about(this,"Error","new name cannot be empty");
        return ;
    }

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(CHANGE_INFORMATION)<<myID.toInt()<<this->ui->id_input->text();
    m_tcpsocket->write(block);

    this->close();
}
