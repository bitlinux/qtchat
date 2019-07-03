#include "add_group_member.h"
#include "ui_add_group_member.h"
#include "QMessageBox"
#include "constant.h"

add_group_member::add_group_member(QWidget *parent, tcpsocket *m, QString gid ) :
    QDialog(parent),
    ui(new Ui::add_group_member)
{
    ui->setupUi(this);
    m_tcpsocket = m;
    groupID = gid;
}

add_group_member::~add_group_member()
{
    delete ui;
}

void add_group_member::on_pushButton_clicked()
{

    this->close();
}

void add_group_member::on_add_clicked()
{
    if(this->ui->lineedit->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("ID cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(FLOCK_ADD_MEMBER)<<groupID.toInt()<<this->ui->lineedit->text().toInt();
    m_tcpsocket->write(block);

    this->close();
}
