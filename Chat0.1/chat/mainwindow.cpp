#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addfriend.h"
#include "creategroup.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>
#include "frienditem.h"
#include "groupitem.h"
#include "noticeitem.h"
#include "editname.h"
#include"tcpsocket.h"
#include"constant.h"
#include "private_chat.h"

MainWindow::MainWindow(QWidget *parent, tcpsocket *m , MainWindowInfo info) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_tcpsocket=m;
    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage(int &)));
    //header path
    QString header_path = "../resources/yl.png";

    //draw header
    QPixmap header_img = QPixmap(header_path).scaled(60,60,Qt::IgnoreAspectRatio);
    this->ui->edit_header->setIcon(header_img);
    this->ui->edit_header->setStyleSheet("QToolButton{border:0px;}");
    this->ui->edit_header->setIconSize(header_img.size());
    this->ui->edit_header->resize(header_img.size());

    //set id & name
    this->myID = info.myID;
    this->myname = info.myname;
    this->ui->id_label->setText(this->myID);
    this->ui->edit_name->setText(this->myname);
    this->ui->edit_name->setStyleSheet("text-align:left;");

    for(int i=0; i<info.friends.size(); i++)
    {
        bool isonline = false;
        if(info.friends[i].isonline == "true")
            isonline = true;
        adfrienditem(header_path = "../resources/yl.png", info.friends[i].ID, info.friends[i].name, isonline);
    }

    for(int i=0; i<info.groups.size(); i++)
    {
        adgroupitem(header_path = "../resources/yl.png", info.groups[i].ID, info.groups[i].name);
    }

    for(int i=0; i<info.notifications.size(); i++)
    {
        adnoticeitem(header_path = "../resources/yl.png", info.notifications[i].ID, info.notifications[i].name, info.notifications[i].time, info.notifications[i].message);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(QUIT);
    m_tcpsocket->write(block);
    m_tcpsocket->close();
}

//add friend item to friend list
void MainWindow::adfrienditem(QString header_path, QString id, QString name, bool isonline)
{

    frienditem *item1 = new frienditem(this, m_tcpsocket, header_path,id,name,this->myID,this->myname,isonline);
    QListWidgetItem *listItem1 = new QListWidgetItem();
    listItem1->setSizeHint(QSize(0, 75));
    ui->friend_list->addItem(listItem1);
    ui->friend_list->setItemWidget(listItem1, item1);

}
//add group item to group list
void MainWindow::adgroupitem(QString header_path, QString id, QString name)
{
    groupitem *item1 = new groupitem(this, m_tcpsocket, header_path, id, name);
    QListWidgetItem *listItem1 = new QListWidgetItem();
    listItem1->setSizeHint(QSize(0, 75));
    ui->group_list->addItem(listItem1);
    ui->group_list->setItemWidget(listItem1,item1);

}

//add notice item to notice list
void MainWindow::adnoticeitem(QString header_path, QString id, QString name, QString time, QString message)
{
    noticeitem *item1 = new noticeitem(this, m_tcpsocket, header_path, this->ui->id_label->text(), id, name, time, message);
    QListWidgetItem *listItem1 = new QListWidgetItem();
    listItem1->setSizeHint(QSize(0, 75));
    ui->notice_list->addItem(listItem1);
    ui->notice_list->setItemWidget(listItem1,item1);


}

// button jump function
void MainWindow::on_adf_but_clicked()
{
    adf = new AddFriend(this, m_tcpsocket, this->ui->id_label->text());
    adf->exec();
}

void MainWindow::on_crgp_but_clicked()
{
    CreateGroup cgp;
    cgp.exec();
}


void MainWindow::on_edit_name_clicked()
{
    editName etn;
    etn.exec();
}

void MainWindow::on_edit_header_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Upload New Header"));
    //this->ui->filename->setText(fileName);
}

void MainWindow:: readmessage(int &type)
{
    if(m_tcpsocket==nullptr)
        return ;
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int otherid;
    switch(type)
    {
        case HAVE_MESSAGE:
    {
        qDebug() << "HAVE_MESSAGE";
        in >> otherid;
        qDebug() << "mainwindow_in";
        QString s = "1" + QString::number(otherid);
        emit send_ID(s);
        break;
    }
    case NO_MESSAGE:
    {
        qDebug() << "NO_MESSAGE";
        in >> otherid;
        qDebug() << "mainwindow_in";
        QString s = "0" + QString::number(otherid);
        emit send_ID(s);
        break;
    }
    case TALK:
    {
        qDebug() << "TALK";
        int meg_send_id;
        in >> meg_send_id;
        qDebug() << "mainwindow_in";
        emit receive_ID(meg_send_id);
        break;
    }
    }
}
