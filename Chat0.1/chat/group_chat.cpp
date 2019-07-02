#include "group_chat.h"
#include "ui_group_chat.h"

group_chat::group_chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::group_chat)
{
    ui->setupUi(this);
}

group_chat::~group_chat()
{
    delete ui;
}

/*get information need for group chat*/
void group_chat::set_information(QString mID, QString mName, QString gID, QString gName, QString gPhoto)
{
    this->myID = mID;
    this->myName = mName;
    this->groupID = gID;
    this->groupName = gName;
    this->groupPhoto = gPhoto;
    this->ui->id->setText(this->groupID);
    this->ui->name->setText(this->groupName);
    QPixmap otherphoto = QPixmap(this->groupPhoto).scaled(40,40,Qt::IgnoreAspectRatio);
    this->ui->photo->setPixmap(otherphoto);
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
    QString time = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    QString meg = this->ui->textedit->toPlainText();
    QString strs = myName + ":   " + time + "\n";
    strs += meg + "\n";
    this->ui->textedit->clear();
    this->ui->chat_browser->insertPlainText(strs);
    //send myID,otherID,time,meg to server
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
    QString time = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    //send myID,otherID,time,file to server
}

/*add new group member*/
void group_chat::on_addnew_clicked()
{
    add_member.show();
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
    QString new_name = this->ui->lineedit->text();
    this->ui->name->setText(new_name);
    this->ui->lineedit->setText("");
    this->groupName = new_name;
    // send groupID,new_name to server
    QString title = title.fromLocal8Bit("Success");
    QString information = information.fromLocal8Bit("The group name has modified successfully!");
    QMessageBox::about(this, title, information);

}

/*receive message*/

/*receive file*/

/*show the add member*/
