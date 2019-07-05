
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
    connect(parent,SIGNAL(send_file(int &)),pchat,SLOT(receive_file(int &)));
    connect(parent,SIGNAL(change_status(int &)),this,SLOT(change_status(int &)));
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

void frienditem::change_status(int &change_id){

    if(m_tcpsocket==nullptr ||change_id != otherID.toInt())
        return;

    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);


    if(this->ui->online_label->text() == "offline"){
        this->ui->online_label->setText("online");
    }
    else{
        this->ui->online_label->setText("offline");
    }

}


