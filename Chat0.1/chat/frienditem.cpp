
#include "frienditem.h"
#include "ui_frienditem.h"
#include "constant.h"
#include <QDebug>


// constructor function need parameter: header_path   id   name
frienditem::frienditem(QWidget *parent, tcpsocket *m, QString header_path, QString id, QString name, QString myid, QString myname, bool isonline) :
    QWidget(parent),
    ui(new Ui::frienditem)
{
    ui->setupUi(this);
    m_tcpsocket = m;
    QPixmap header_img = QPixmap(header_path).scaled(60,60,Qt::IgnoreAspectRatio);
    this->ui->header_button->setIcon(header_img);
    this->ui->header_button->setStyleSheet("QToolButton{border:0px;}");
    this->ui->header_button->setIconSize(header_img.size());
    this->ui->header_button->resize(header_img.size());
    this->ui->id_label->setText(id);
    this->ui->name_label->setText(name);
    if(isonline)
        this->ui->online_label->setText("online");
    this->myID = myid;
    this->myname = myname;
    this->otherID = id;
    this->othername = name;
    this->header_path = header_path;
    pchat = new private_chat(nullptr, m_tcpsocket);
    connect(parent,SIGNAL(send_ID(QString &)),pchat,SLOT(readID(QString &)));
    connect(parent,SIGNAL(receive_ID(int &)),pchat,SLOT(readmessage(int &)));
    connect(parent,SIGNAL(send_record_ID(QString &)),pchat,SLOT(read_record_message(QString &)));


}

frienditem::~frienditem()
{
    delete ui;
}

void frienditem::on_header_button_clicked()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(CHECK_MESSAGE)<<this->myID.toInt()<<this->otherID.toInt();
    m_tcpsocket->write(block);
    pchat->set_information(this->myID, this->myname, this->otherID, this->othername, this->header_path);
    pchat->show();
}


