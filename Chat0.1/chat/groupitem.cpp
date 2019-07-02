#include "groupitem.h"
#include "ui_groupitem.h"

groupitem::groupitem(QWidget *parent, tcpsocket *m, QString header_path, QString id, QString name):
    QWidget(parent),
    ui(new Ui::groupitem)
{
    ui->setupUi(this);

    QPixmap header_img = QPixmap(header_path).scaled(60,60,Qt::IgnoreAspectRatio);
    this->ui->header_button->setIcon(header_img);
    this->ui->header_button->setStyleSheet("QToolButton{border:0px;}");
    this->ui->header_button->setIconSize(header_img.size());
    this->ui->header_button->resize(header_img.size());
    this->ui->id_label->setText(id);
    this->ui->name_label->setText(name);
}

groupitem::~groupitem()
{
    delete ui;
}

void groupitem::on_header_button_clicked()
{
    group_chat *gchat = new group_chat();
    //gchat->set_information(this->myID, this->myname, this->otherID, this->othername, this->header_path);
    gchat->show();
}
