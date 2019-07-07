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
#include "tcpsocket.h"
#include "constant.h"
#include "private_chat.h"
#include "bbs.h"

MainWindow::MainWindow(QWidget *parent, tcpsocket *m , MainWindowInfo info) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);  
    m_tcpsocket=m;
    qDebug()<< "test1";

    qDebug()<< "test2";
    connect(m_tcpsocket,SIGNAL(send_type(int &)),this,SLOT(readmessage(int &)));
    connect(this,SIGNAL(fresh_list(int &)),this,SLOT(get_new_friend(int &)));
    connect(this,SIGNAL(new_noti(int &)),this,SLOT(get_new_noti(int &)));

    qDebug()<< "test3";
    //header path
    QString header_path = "../resources/";
    //draw header
    QPixmap header_img = QPixmap(header_path + info.myID + ".png").scaled(60,60,Qt::IgnoreAspectRatio);
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
        if(info.friends[i].isonline == true)
            isonline = true;
        adfrienditem(header_path = "../resources/" + info.friends[i].ID + ".png", info.friends[i].ID, info.friends[i].name, isonline);
    }

    for(int i=0; i<info.groups.size(); i++)
    {
        adgroupitem(info.groups[i].ID, info.groups[i].name);
    }

    for(int i=0; i<info.notifications.size(); i++)
    {
        adnoticeitem(header_path = "../resources/" + info.notifications[i].ID + ".png", info.notifications[i].ID, info.notifications[i].name, info.notifications[i].time, info.notifications[i].message);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

// tell server quit envent
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
void MainWindow::adgroupitem(QString gID, QString gname, QString gphoto)
{
    groupitem *item1 = new groupitem(this, m_tcpsocket, this->ui->id_label->text(), gID, gname, {});
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

//get new noti online
void MainWindow::get_new_noti(int &apply_id){
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    QString msg,time,name,header_path;
    in >> msg >> time >> name;
    header_path = "../resources/" + QString::number(apply_id) + ".png";
    adnoticeitem(header_path, QString::number(apply_id), name, time, msg);
}

// fresh friend list after add friend
void MainWindow::get_new_friend(int &newfriend_id){
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    QString header_path,name;
    header_path = "../resources/" + QString::number(newfriend_id) + ".png";
    int is_online;
    bool isonline;
    in >> name >>is_online;
    isonline = (is_online==1)?true:false;
    adfrienditem(header_path, QString::number(newfriend_id),name,isonline);
    del_noti(newfriend_id);
}

// delete friend notice after agree
void MainWindow::del_noti(int delete_id){
    int cnt = ui->notice_list->count();
    for(int i = 0;i<cnt;i++){
        QListWidgetItem *pitem = ui->notice_list->item(i);
        //istWidget::itemWidget(QListWidgetItem *item) const pitem)
        noticeitem *nitem = qobject_cast<noticeitem *>(ui->notice_list->itemWidget(ui->notice_list->item(i)));
        if( nitem-> otherID == QString::number(delete_id)){
            ui->notice_list->removeItemWidget(pitem);
            qDebug()<<"delete item";
            delete nitem;
            delete pitem;
            break;
        }
    }
}

// add friend button
void MainWindow::on_adf_but_clicked()
{
    adf = new AddFriend(this, m_tcpsocket, this->ui->id_label->text());
    adf->exec();
}

// create group button
void MainWindow::on_crgp_but_clicked()
{
    CreateGroup *cgp;
    cgp = new CreateGroup(this, m_tcpsocket, this->ui->id_label->text());
    cgp->exec();
}

// edit name button
void MainWindow::on_edit_name_clicked()
{
    editName *etn;
    etn = new editName(this, m_tcpsocket, this->ui->id_label->text());
    etn->exec();
}

// jump to bbs UI button
void  MainWindow::on_bbs_but_clicked()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(GET_ALL_BBS)<<this->ui->id_label->text().toInt();
    qDebug()<<"request get all bbs";
    m_tcpsocket->write(block);
    bbs *bbs_window;
    bbs_window = new bbs(nullptr, m_tcpsocket, this->ui->id_label->text(),this->ui->edit_name->text());
    bbs_window->show();
    bbs_window->setWindowTitle("BBS");
    connect(this,SIGNAL(get_bbs_list()),bbs_window,SLOT(get_item()));
    connect(this,SIGNAL(get_new_bbsitem()),bbs_window,SLOT(get_single_item()));
    connect(this,SIGNAL(get_bbs_history()),bbs_window,SLOT(pass_bbs_history()));
}

// edit header button
void MainWindow::on_edit_header_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Upload New Header"));
    //this->ui->filename->setText(fileName);
}

// process incoming message
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
    case HAVE_MESSAGE_RECORD:
    {
        qDebug() << "HAVE_MESSAGE_RECORD";
        int temp;
        in >> temp;
        qDebug() << "mainwindow_in";
        QString s = "1" + QString::number(temp);
        emit send_record_ID(s);
        break;
    }
    case NO_MESSAGE_RECORD:

    {
        qDebug() << "NO_MESSAGE_RECORD";
        int temp;
        in >> temp;
        qDebug() << "mainwindow_in";
        QString s = "0" + QString::number(temp);
        emit send_record_ID(s);
        break;
    }
    case GET_FLOCK_MEMBERS_SUCCESS:
    {
        qDebug() << "GET_FLOCK_MEMBERS_SUCCESS";
        int temp;
        in >> temp;
        qDebug() << "mainwindow_in";
        QString s = "1" + QString::number(temp);
        emit send_ID(s);
        break;
    }
    case GET_FLOCK_MEMBERS_FAIL:
    {
        qDebug() << "GET_FLOCK_MEMBERS_FAIL";
        int temp;
        in >> temp;
        qDebug() << "mainwindow_in";
        QString s = "0" + QString::number(temp);
        emit send_ID(s);
        break;
    }
    case ADD_FLOCK_SUCCESS:
    {
        qDebug() << "ADD_FLOCK_SUCCESS";
        int groupid;
        in >> groupid;
        qDebug() << "mainwindow_in";
        QString s = QString::number(groupid) + " add new member success.";
        QMessageBox::about(this, "Success", s);
        break;
    }
    case ADD_FLOCK_FAIL:
    {
        qDebug() << "ADD_FLOCK_FAIL";
        int groupid;
        in >> groupid;
        qDebug() << "mainwindow_in";
        QString s = QString::number(groupid) + " add new member false.";
        QMessageBox::about(this, "Error", s);
        break;
    }
    case CHANGE_FLOCK_NAME_SUCCESS:
    {
        qDebug() << "CHANGE_FLOCK_NAME_SUCCESS";
        int groupid;
        in >> groupid;
        qDebug() << "mainwindow_in";
        QString s = "1" + QString::number(groupid);
        emit change_name(s);
        break;
    }
    case CHANGE_FLOCK_NAME_FAIL:
    {
        qDebug() << "CHANGE_FLOCK_NAME_FAIL";
        int groupid;
        in >> groupid;
        qDebug() << "mainwindow_in";
        QString s = "0" + QString::number(groupid);
        emit change_name(s);
        break;
    }
    case CHANGE_INFORMATION_SUCCESS:
    {
        qDebug() << "CHANGE_INFORMATION_SUCCESS";
        QString newname;
        in >> newname;
        this->ui->edit_name->setText(newname);
        myname = newname;
        QMessageBox::about(this,"Success","Change name success.");
        break;
    }
    case CHANGE_INFORMATION_FAIL:
    {
        qDebug() << "CHANGE_INFORMATION_FAIL";
        QMessageBox::about(this,"Error","Fail to change name.");
        break;
    }
    case TALK_FLOCK:
    {
        qDebug() << "TALK_FLOCK";
        int meg_send_id;
        in >> meg_send_id;
        qDebug() << "mainwindow_in";
        emit receive_ID(meg_send_id);
        break;
    }
    case HAVE_FLOCK_MESSAGE:
    {
        qDebug() << "HAVE_FLOCK_MESSAGE";
        int groupid;
        in >> groupid;
        qDebug() << "mainwindow_in";
        QString s = "1" + QString::number(groupid);
        emit init_flock_message(s);
        break;
    }
    case NO_FLOCK_MESSAGE:
    {
        qDebug() << "NO_FLOCK_MESSAGE";
        int groupid;
        in >> groupid;
        qDebug() << "mainwindow_in";
        QString s = "0" + QString::number(groupid);
        emit init_flock_message(s);
        break;
    }
    case SEND_FILE_TO_PEER:
    {
        qDebug()<< "SEND_FILE_TO_PEER";
        int send_id;
        in >> send_id;
        emit send_file(send_id);
        break;
    }
    case CHANGE_STATUE:
    {
        qDebug()<< "Change_statue";
        int change_id;
        in >> change_id;
        emit change_status(change_id);
        break;
    }
    case NEW_NOTI_FRIEND:{
        qDebug()<<"New noti friend";
        int apply_id;
        in >> apply_id;
        emit new_noti(apply_id);
        break;
    }
    case FRESH_FRIEND_LIST:{
        qDebug()<<"fresh_friend_list";
        int newfirend_id;
        in >> newfirend_id;
        emit fresh_list(newfirend_id);
        break;
    }
    case GET_BBS_SUCCESS:{
        qDebug()<<"get_bbs_success";
        int judge_id;
        in >> judge_id;
        if(judge_id != ui->id_label->text().toInt())
            break;
        emit get_bbs_list();
        break;
    }
    case POST_BBS:{
        qDebug()<<"get_new_bbsitem call";
        emit get_new_bbsitem();
        break;
    }
    case REPLY_BBS_HISTORY:{
        qDebug()<<"reply_bbs_history";
        emit get_bbs_history();
        break;
    }
    }
}


