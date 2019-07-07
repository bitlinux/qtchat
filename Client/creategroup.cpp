#include "creategroup.h"
#include "ui_creategroup.h"
#include <QMessageBox>
#include "constant.h"
#include "group_chat.h"

CreateGroup::CreateGroup(QWidget *parent, tcpsocket *m, QString myid) :
    QDialog(parent),
    ui(new Ui::CreateGroup)
{
    ui->setupUi(this);
    m_tcpsocket = m;
    myID = myid;
     connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage(int &)));
}

CreateGroup::~CreateGroup()
{
    delete ui;
}

void CreateGroup::on_pushButton_clicked()
{
    if(this->ui->gpname_input->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Group's name can not be empty.");
        QMessageBox::about(this, title, information);
        return ;
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    qDebug() << myID.toInt()<<this->ui->gpname_input->text();
    out<<int(CREATE_FLOCK)<<myID.toInt()<<this->ui->gpname_input->text();
    qDebug() << "after_send";
    m_tcpsocket->write(block);
}

void CreateGroup::readmessage(int &type)
{
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    switch(type)
    {
        case CREATE_FLOCK_SUCCESS:
    {
        qDebug() << "CREATE_FLOCK_SUCCESS";
        int groupID;
        in >> groupID;
        group_chat *gc;
        gc = new group_chat();
        FlockMember mem;
        mem.user_id = myID.toInt();
        mem.flock_id = groupID;
        mem.loginStatus = 1;
        mem.flockStatus = 1;
        QVector<FlockMember> temp;
        temp.append(mem);
        gc->set_information(m_tcpsocket, myID, QString::number(groupID), this->ui->gpname_input->text(), temp);
        gc->show();
        this->close();
        break;
    }
    case CREATE_FLOCK_FAIL:
    {
        qDebug() << "CREATE_FLOCK_FAIL";
        QMessageBox::about(this, "ERROR", "Fail to create flock.");
        break;
    }
    }
}
