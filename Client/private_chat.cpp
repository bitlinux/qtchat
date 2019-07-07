#include "private_chat.h"
#include "ui_private_chat.h"
#include "constant.h"
#include <QTextCodec>
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
    chat_message = new private_chat_message(this);
    chat_message->show();
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(MESSAGE_RECORD)<<this->myID.toInt()<<this->otherID.toInt();
    m_tcpsocket->write(block);
}

/*choose file*/
void private_chat::on_file_clicked()
{
    qDebug()<<"on_file_clicked";
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
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString meg = this->ui->textedit->toPlainText();
    QString strs = "                " + time + "\n" + myID + ":   ";
    strs += meg + "\n";
    this->ui->textedit->clear();
    this->ui->chat_browser->append(strs);

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(TALK)<<myID.toInt()<<otherID.toInt()<<meg;
    m_tcpsocket->write(block);

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

    /*if(!file->open(QFile::ReadOnly))
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Can not open the file!");
        QMessageBox::about(this, title, information);
        return ;
    }
    this->ui->filename->setText("");
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    //send myID,otherID,time,file to server
    */
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    file->open(QIODevice::ReadOnly);

    out<<int(SEND_FILE_TO_PEER)<<myID.toInt()<<otherID.toInt()<<filename<<file->readAll();
    file->close();
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    //
    QString filesent = "                " + time + "\n" + myID + ":   ";
    filesent += "Sent file (" + filename + ")  \n";
    this->ui->chat_browser->append(filesent); //

    this->ui->filename->setText("");    //reset filename
    m_tcpsocket->write(block);


}

// receive file and save to local storage
void private_chat::receive_file(int &send_ID){
    qDebug()<<"receive_file";
    if(m_tcpsocket==nullptr || send_ID != otherID.toInt())
        return ;

    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    QString filename;
    in >> filename;
    QByteArray file_content;
    in >> file_content;
    QString time;
    in >> time;
    // save to local

    //QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QStringList filename_list = filename.split("/");

    QString file_path =  "../" + myID + "/" + filename_list[filename_list.count()-1];

    qDebug()<<filename_list[filename_list.count()-1];
    QString strs = "                " + time + "\n" + otherID + ":   ";
    strs += "Receieve file (" + filename_list[filename_list.count()-1] + ")  \n";
    this->ui->chat_browser->append(strs);
    QFile p_file(file_path);
    QDataStream data_stream(&p_file);
    data_stream.setVersion(QDataStream::Qt_4_8);
    p_file.open(QIODevice::WriteOnly);

    //QPixmap imga;
    //qDebug() << file_content.size();
    //imga.loadFromData(file_content);
    //qDebug() << file_path;
    //imga.save(&p_file,"png");
    //qDebug() << "save" ;
    data_stream << file_content ;
    p_file.close();

    //qDebug()<<codec->toUnicode(file_content);

}

// read incoming message and display on left textview
void private_chat::readmessage(int &send_ID)
{
    qDebug()<<"readmessage";
    if(m_tcpsocket==nullptr || send_ID != otherID.toInt())
        return ;

    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    QString message;
    in>>message;


    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString strs = "                " + time + "\n" + otherID + ":   ";
    strs += message + "\n";
    this->ui->chat_browser->append(strs);
    qDebug() << "readmessage" << strs;
}

// please fill
void private_chat::readID(QString &id)
{
    QString getid = id.mid(1,-1);
    qDebug() << "message" << getid << otherID << (getid==otherID);
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
        QString time = userinfo[i].send_time;
        QString strs = "                " + time + "\n" + QString::number(userinfo[i].send_id) + ":   ";
        strs += userinfo[i].message + "\n";
        this->ui->chat_browser->append(strs);
    }

}

// read all message history
void private_chat::read_record_message(QString &s)
{

    QString id = s.mid(1,-1);
    qDebug() << "record" << id << otherID ;
    if(id != otherID)
    {
        return ;
    }
    if(s[0] == '0')
    {
        qDebug()<<"0";
        return ;
    }
    if(m_tcpsocket==nullptr)
        return ;
    recordinfo = {};
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int length;
    in >> length;
    for(int i=0; i<length; i++)
    {
        UserTalkinfo utalk;
        in >> utalk.send_id >> utalk.message >> utalk.send_time;
        recordinfo.append(utalk);
    }

    chat_message->set_information(recordinfo);
}


