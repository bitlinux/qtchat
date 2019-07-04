#include "bbsitem.h"
#include "ui_bbsitem.h"

bbsitem::bbsitem(QWidget *parent, tcpsocket *m, QString bbs_id ,QString ititle, QString icontent, QString iname) :
    QWidget(parent),
    ui(new Ui::bbsitem)
{
    ui->setupUi(this);
    //process title or title.length<15
    this->title = ititle;
    //process content
    this->content = icontent;
    this->name = iname;

    this->ui->post_title->setText(this->title);
    // title align left
    this->ui->post_title->setStyleSheet("text-align:left;");

    this->ui->content_label->setText(this->content);
    this->ui->content_label->setStyleSheet("text-align:left;");

    this->ui->poster_name->setText(this->name);
    //name align right
    this->ui->poster_name->setStyleSheet("text-align:right;");
    this->bbs_id = bbs_id;
}

bbsitem::~bbsitem()
{
    delete ui;
}
