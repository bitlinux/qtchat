#include "noticeitem.h"
#include "ui_noticeitem.h"
#include "notice_dialog.h"

noticeitem::noticeitem(QWidget *parent, tcpsocket *m, QString header_path, QString myid, QString id, QString name, QString time,  QString mge) :
    QWidget(parent),
    ui(new Ui::noticeitem)
{
    ui->setupUi(this);
    QPixmap header_img = QPixmap(header_path).scaled(60,60,Qt::IgnoreAspectRatio);
    message = mge;
    myID = myid;
    m_tcpsocket = m;
    otherID = id;
    this->ui->header_button->setIcon(header_img);
    this->ui->header_button->setStyleSheet("QToolButton{border:0px;}");
    this->ui->header_button->setIconSize(header_img.size());
    this->ui->header_button->resize(header_img.size());
    this->ui->id_label->setText(id);
    this->ui->name_label->setText(name);
    this->ui->time_label->setText(time);

}

noticeitem::~noticeitem()
{
    delete ui;
}

void noticeitem::on_header_button_clicked()
{
    notice_dialog ndialog(this, m_tcpsocket, myID, this->ui->id_label->text(), this->ui->name_label->text(), this->ui->time_label->text(), message);
    ndialog.exec();
}
