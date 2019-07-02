#include "private_chat.h"
#include "ui_private_chat.h"
#include "constant.h"

private_chat::private_chat(QWidget *parent, tcpsocket *m) :
    QWidget(parent),
    ui(new Ui::private_chat)
{
    m_tcpsocket = m;
    ui->setupUi(this);
    ui->chat_browser->setText("");
    userinfo = {};
}

private_chat::~private_chat()
{
    delete ui;
}

/*get the information need for chat*/
void private_chat::set_information(QString mID, QString mName, QString oID, QString oName, QString oPhoto)
{
    this->myID = mID;
    this->myName = mName;
    this->otherID = oID;
    this->otherName = oName;
    this->otherPhoto = oPhoto;
    this->ui->id->setText(this->otherID);
    this->ui->name->setText(this->otherName);
    QPixmap otherphoto = QPixmap(this->otherPhoto).scaled(40,40,Qt::IgnoreAspectRatio);
    this->ui->photo->setPixmap(otherphoto);
}

/*show the chat_message window*/
void private_chat::on_records_clicked()
{
    chat_message.setWindowFlags(Qt::FramelessWindowHint);
    //get all the chat_message from server?
    chat_message.show();
}

/*choose file*/
void private_chat::on_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose a File"));
    this->ui->filename->setText(fileName);
}

/*send message*/
void private_chat::on_send_clicked()
{
    if(this->ui->textedit->toPlainText().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("The sending message cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    QString time = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    QString meg = this->ui->textedit->toPlainText();
    QString strs = "                " + time + "\n" + myID + ":   ";
    strs += meg + "\n" + "\n";
    this->ui->textedit->clear();
    this->ui->chat_browser->insertPlainText(strs);
    qDebug() << "send_clicked";

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(TALK)<<myID.toInt()<<otherID.toInt()<<meg;
    m_tcpsocket->write(block);

    qDebug() << "end of send click";

}

/*send_file*/
void private_chat::on_sendfile_clicked()
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
    QString time = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    //send myID,otherID,time,file to server
}

void private_chat::readmessage(int &send_ID)
{
    if(m_tcpsocket==nullptr || send_ID != otherID.toInt())
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    QString message;
    in>>message;
    QString time = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    QString strs = "                " + time + "\n" + otherID + ":   ";
    strs += message + "\n" + "\n";
    this->ui->chat_browser->insertPlainText(strs);
    qDebug() << "readmessage" << strs;
}

void private_chat::readID(QString &id)
{
    QString getid = id.mid(1,-1);
    qDebug() << getid << otherID << (getid==otherID);
    if(getid != otherID || id[0] == '0')
        return ;
    if(m_tcpsocket==nullptr)
        return ;
    ui->chat_browser->setText("");
    userinfo = {};
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int length;
    in >> length;
    for(int i=0; i<length; i++)
    {
        UserTalkinfo utalk;
        in >> utalk;
        userinfo.append(utalk);
    }
    qDebug() << "private_chat_in" << userinfo.size();
    for(int i=0; i<userinfo.size();i++)
    {
        QString time = userinfo[i].send_time.toString("yyyy.MM.dd hh:mm:ss");
        QString strs = "                " + time + "\n" + QString::number(userinfo[i].send_id) + ":   ";
        strs += userinfo[i].message + "\n" + "\n";
        this->ui->chat_browser->insertPlainText(strs);
        qDebug() << "readID";
    }

}

/*receive file*/


