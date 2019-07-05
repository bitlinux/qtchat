#include "group_chat.h"
#include "ui_group_chat.h"

group_chat::group_chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::group_chat)
{
    ui->setupUi(this);
    ui->member_browser->setText("");
}

group_chat::~group_chat()
{
    delete ui;
}

/*get information need for group chat*/
void group_chat::set_information(tcpsocket *m, QString mID, QString gID, QString gName, QVector<FlockMember> fm, QString gPhoto)
{
    ui->member_browser->setText("");
    ui->chat_browser->setText("");
    this->myID = mID;
    this->groupID = gID;
    this->groupName = gName;
    this->groupPhoto = gPhoto;
    this->ui->id->setText(this->groupID);
    this->ui->name->setText(this->groupName);
    QPixmap otherphoto = QPixmap(this->groupPhoto).scaled(40,40,Qt::IgnoreAspectRatio);
    this->ui->photo->setPixmap(otherphoto);
    m_tcpsocket = m;
    for(int i=0;i<fm.size();i++)
    {
        QString online = "No";
        if(fm[i].loginStatus == 1)
            online = "Yes";
        QString a = "  " + QString::number(fm[i].user_id) + "         " + online + "\n";
        ui->member_browser->insertPlainText(a);
    }

    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage(int &)));

    //get all the group members from server
}

/*show the group chat message window*/
void group_chat::on_records_clicked()
{
    chat_message.setWindowFlags(Qt::FramelessWindowHint);
    //get all the chat_message from server?
    chat_message.show();
}

/*choose file*/
void group_chat::on_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose a File"));
    this->ui->filename->setText(fileName);
}

/*send message*/
void group_chat::on_send_clicked()
{
    if(this->ui->textedit->toPlainText().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("The sending message cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    QString meg = this->ui->textedit->toPlainText();
    this->ui->textedit->clear();
    /*
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString strs = myID + ":   " + time + "\n";
    strs += meg + "\n";
    this->ui->chat_browser->insertPlainText(strs);*/

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(TALK_FLOCK)<<myID.toInt()<<groupID.toInt()<<meg;
    m_tcpsocket->write(block);

}

/*send file*/
void group_chat::on_sendfile_clicked()
{
    QString filename = this->ui->filename->text();
    if(filename.length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("The sending file cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    QFile *file = new QFile(filename);
    if(!file->open(QFile::ReadOnly))
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Can not open the file!");
        QMessageBox::about(this, title, information);
        return ;
    }
    this->ui->filename->setText("");
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    //send myID,otherID,time,file to server
}

/*add new group member*/
void group_chat::on_addnew_clicked()
{
    add_member = new add_group_member(this, m_tcpsocket, groupID);
    add_member->show();
}

/*change group name*/
void group_chat::on_change_clicked()
{
    if(this->ui->lineedit->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("The new group name cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    newname = this->ui->lineedit->text();
    this->ui->lineedit->setText("");
    this->groupName = newname;

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(CHANGE_FLOCK_NAME)<<groupID.toInt()<<newname;
    m_tcpsocket->write(block);
}

void group_chat::readmember(QString &s)
{   QString id = s.mid(1,-1);
    qDebug() << "record" << id << groupID ;
    if(id != groupID)
    {
        return ;
    }
    if(s[0] == '0')
    {
        QString a = "  " + myID + "         " + "Yes" + "\n";
        return ;
    }
    if(m_tcpsocket==nullptr)
        return ;
    int length;
    member = {};
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    in >> length;
    for(int i=0; i<length; i++)
    {
        FlockMember fm;
        in >> fm.user_id >> fm.loginStatus;
        QString online = "No";
        if(fm.loginStatus == 1)
            online = "Yes";
        QString a = "  " + QString::number(fm.user_id) + "         " + online + "\n";
        ui->member_browser->insertPlainText(a);
    }

}

void group_chat::changename(QString &s)
{
    QString id = s.mid(1,-1);
    if(id != groupID)
    {
        return ;
    }
    if(s[0] == '0')
    {
        QMessageBox::about(this, "Error", "Fail to change name.");
        return ;
    }
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    newname = "";
    in >> newname;
    QMessageBox::about(this, "Success", "Change name success.");
    this->ui->name->setText(newname);

}

void group_chat::readmessage(int &gid)
{
    if(m_tcpsocket==nullptr ||  gid != groupID.toInt())
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int sendid;
    QString message;
    QString time;
    in>> sendid >> message >> time;
    QString strs = "            " + time + "\n" + QString::number(sendid) + ":   ";
    strs += message + "\n";
    this->ui->chat_browser->append(strs);
    qDebug() << "readmessage" << strs;
}

void group_chat::init_message(QString &s)
{
    QString id = s.mid(1,-1);
    if(id != groupID)
    {
        return ;
    }
    if(s[0] == '0')
    {
        return ;
    }
    if(m_tcpsocket==nullptr)
        return ;
    ui->member_browser->setText("");
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int length;
    in >> length;
    for(int i=0; i<length; i++)
    {
        int sendid;
        QString message;
        QString time;
        in >> sendid >> message >> time;
        QString strs = "            " + time + "\n" + QString::number(sendid) + ":   ";
        strs += message + "\n";
        this->ui->chat_browser->append(strs);
    }
    QByteArray block1;
    QDataStream out1(&block1,QIODevice::WriteOnly);
    out1.setVersion(QDataStream::Qt_4_8);
    out1<<int(GET_FLOCK_MEMBERS)<<groupID.toInt();
    m_tcpsocket->write(block1);
}
/*receive file*/

