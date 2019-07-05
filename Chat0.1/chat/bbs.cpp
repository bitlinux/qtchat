#include "bbs.h"
#include "ui_bbs.h"
#include "newpostwindow.h"
//#include "mainwindow.h"

bbs::bbs(QWidget *parent, tcpsocket *m, QString myID, QString myname) :
    QWidget(parent),
    ui(new Ui::bbs)
{
    ui->setupUi(this);
    m_tcpsocket = m;
    this->myid = myID;
    this->myname = myname;
    qDebug()<<"bbs";
    // for loop to get item
}

bbs::~bbs()
{
    delete ui;
}

// pass get history signal
void bbs::pass_bbs_history(){
    emit to_bbs_item();
    qDebug()<<"Pass history signal to bbs success";
}

// add bbsitem
void bbs::adbbsitem(QString title, QString content, QString name, QString bbs_id, QString poster_id, QString my_id,QString post_time){
   // qDebug()<<"add to bbs before";
   qDebug()<<bbs_id<<title;
   bbsitem *item1 = new bbsitem(this, m_tcpsocket, bbs_id, poster_id, my_id, title, content, name, post_time);
   connect(this,SIGNAL(to_bbs_item()),item1,SLOT(pass_signal()));
   // qDebug()<<"bbstiem construstor"<<bbs_id<<poster_id;
   QListWidgetItem *listItem1 = new QListWidgetItem();
   listItem1->setSizeHint(QSize(0, 90));
   this->ui->bbs_list->addItem(listItem1);
   this->ui->bbs_list->setItemWidget(listItem1, item1);

}

// open shared file UI
void bbs::on_shared_button_clicked()
{

}

// open post(发帖）UI
void bbs::on_postButton_clicked()
{
    NewPostWindow *psw;
    psw = new NewPostWindow(nullptr,m_tcpsocket,myid);
    psw->show();
    psw->setWindowTitle("New Post");
}

// open file uploab UI
void bbs::on_upload_button_clicked()
{

}

// quit bbs UI and send quit signal
void bbs::on_quitButton_clicked()
{
    this->close();
    //delete this->ui;
}

// Besides, when close bbs windows tell server bbs_exit, too.
void bbs::closeEvent(QCloseEvent *event)
{
    //this->close();
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(EXIT_BBS)<<myid.toInt();
    m_tcpsocket->write(block);
    this->deleteLater();
    qDebug()<<"delete this";
}

// load bbs item from server
void bbs::get_item(){
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int length;

    in >> length;
    qDebug()<<length;
    //qDebug()<<"get bbs item call" << QString::number(length);
    for(int i=0; i<length; i++)
    {
        bbsItem bbbsitem;
        in >> bbbsitem.id >>bbbsitem.poster_id>> bbbsitem.name >> bbbsitem.title >> bbbsitem.content >>bbbsitem.posttime;
        qDebug()<< bbbsitem.id <<bbbsitem.poster_id<< bbbsitem.name << bbbsitem.title << bbbsitem.content << bbbsitem.posttime;
        bbsItems.append(bbbsitem);
    }
    //qDebug()<<"before add bbs item";
    for(int i=0;i<length; i++){
        adbbsitem(this->bbsItems[i].title,bbsItems[i].content,bbsItems[i].name,QString::number(bbsItems[i].id),QString::number(bbsItems[i].poster_id),this->myid, bbsItems[i].posttime);
        qDebug()<<this->bbsItems[i].id<<bbsItems[i].title;
    }
    //qDebug()<<"after add bbs item";

}

// get item while other people post a new post.
void bbs::get_single_item(){
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    qDebug()<<"get_single_item called";
    bbsItem bbbsitem;
    in >> bbbsitem.id >> bbbsitem.poster_id>> bbbsitem.name >> bbbsitem.title >> bbbsitem.content >> bbbsitem.posttime;

    adbbsitem(bbbsitem.title,bbbsitem.content,bbbsitem.name,QString::number(bbbsitem.id),QString::number(bbbsitem.poster_id),this->myid, bbbsitem.posttime);

}
