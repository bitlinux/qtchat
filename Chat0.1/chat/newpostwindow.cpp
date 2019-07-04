#include "newpostwindow.h"
#include "ui_newpostwindow.h"
#include "constant.h"

NewPostWindow::NewPostWindow(QWidget *parent, tcpsocket *m, QString myid) :
    QDialog(parent),
    ui(new Ui::NewPostWindow)
{
    ui->setupUi(this);
    this->id = myid;
    m_tcpsocket = m;
}

NewPostWindow::~NewPostWindow()
{
    delete ui;
}

// return title as a QString
QString NewPostWindow::getTitle(){
    return ui->titleEdit->text();
}

// get contennt and return a QString
QString NewPostWindow::getContent(){
    return ui->contentEdit->toPlainText();
}

bool NewPostWindow::isContentEmpty(){
    return ui->contentEdit->toPlainText().isEmpty();
}

// after click ok button send ID << title << content   to server

void NewPostWindow::on_buttonBox_accepted()
{

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(POST_BBS)<<id.toInt()<<this->getTitle()<<this->getContent();
    m_tcpsocket->write(block);
    qDebug()<<this->getTitle();
    qDebug()<<this->getContent();

}
