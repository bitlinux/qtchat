#include "groupitem.h"
#include "ui_groupitem.h"

groupitem::groupitem(QWidget *parent, tcpsocket *m, QString myid, QString gID, QString gname, QVector<FlockMember> fmember, QString gphoto):
    QWidget(parent),
    ui(new Ui::groupitem)
{
    ui->setupUi(this);

    QPixmap header_img = QPixmap(gphoto).scaled(60,60,Qt::IgnoreAspectRatio);
    this->ui->header_button->setIcon(header_img);
    this->ui->header_button->setStyleSheet("QToolButton{border:0px;}");
    this->ui->header_button->setIconSize(header_img.size());
    this->ui->header_button->resize(header_img.size());
    this->ui->id_label->setText(gID);
    this->ui->name_label->setText(gname);
    m_tcpsocket = m;
    myID = myid;
    groupID = gID;
    groupname = gname;
    fm = fmember;
    gchat = new group_chat();
    connect(parent, SIGNAL(send_ID(QString &)), gchat, SLOT(readmember(QString &)));
    connect(parent, SIGNAL(change_name(QString &)), gchat, SLOT(changename(QString &)));
    connect(parent, SIGNAL(receive_ID(int &)), gchat, SLOT(readmessage(int &)));
    connect(parent, SIGNAL(init_flock_message(QString &)), gchat, SLOT(init_message(QString &)));
}

groupitem::~groupitem()
{
    delete ui;
}

void groupitem::on_header_button_clicked()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(CHECK_FLOCK_MESSAGE)<<groupID.toInt();
    m_tcpsocket->write(block);

    gchat->set_information(m_tcpsocket, myID, groupID, groupname, fm);
    gchat->show();

}
