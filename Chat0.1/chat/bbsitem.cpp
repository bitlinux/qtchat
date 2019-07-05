#include "bbsitem.h"
#include "ui_bbsitem.h"

bbsitem::bbsitem(QWidget *parent, tcpsocket *m, QString bbs_id, QString poster_id, QString my_id ,QString ititle, QString icontent, QString iname, QString post_time) :
    QWidget(parent),
    ui(new Ui::bbsitem)
{
    ui->setupUi(this);
    //process title or title.length<15
    this->title = ititle;
    //process content
    this->content = icontent;
    this->otherName = iname;
    this->postTime = post_time;
    this->m_tcpsocket = m;
    this->posterID = poster_id;
    this->myID = my_id;
    this->ui->post_title->setText(this->title);
    // title align left
    this->ui->post_title->setStyleSheet("text-align:left;");

    this->ui->content_label->setText("    "+this->content);
    this->ui->content_label->setStyleSheet("text-align:left;");

    this->ui->poster_name->setText(this->otherName);
    //name align right
    this->ui->poster_name->setStyleSheet("text-align:right;color:gray;");
    this->bbs_id = bbs_id;
}

bbsitem::~bbsitem()
{
    delete ui;
}

// open bbs detial UI
void bbsitem::on_post_title_clicked()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(REPLY_BBS_HISTORY)<<this->bbs_id;
    m_tcpsocket->write(block);
    bbsitem_detail *detail_dialog;
    detail_dialog = new bbsitem_detail(nullptr,m_tcpsocket,this->bbs_id,this->posterID,this->myID,this->content,this->title,this->otherName,this->postTime);
    detail_dialog->show();
}
