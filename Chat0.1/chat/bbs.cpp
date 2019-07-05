#include "bbs.h"
#include "ui_bbs.h"
#include "newpostwindow.h"
//#include "mainwindow.h"

bbs::bbs(QWidget *parent, tcpsocket *m, QString myID, QString myname, QWidget *sig) :
    QWidget(parent),
    ui(new Ui::bbs)
{
    ui->setupUi(this);
    m_tcpsocket = m;
    this->id = myID;
    this->name = myname;
    connect(sig,SIGNAL(get_bbs_list()),this,SLOT(get_item()));
    //connect(sig,SIGNAL(get_new_bbs_item()),this,SLOT(get_single_item()));
    qDebug()<<"bbs";
    // for loop to get item
}

bbs::~bbs()
{
    delete ui;
}

// add bbsitem
void bbs::adbbsitem(QString title, QString content, QString name, QString bbs_id){

   bbsitem *item1 = new bbsitem(this, m_tcpsocket, bbs_id,title, content, name);
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
    psw = new NewPostWindow(nullptr,m_tcpsocket,id);
    psw->show();
    psw->setWindowTitle("New Post");
}

// open file uploab UI
void bbs::on_upload_button_clicked()
{

}

// quit bbs UI
void bbs::on_quitButton_clicked()
{
    this->close();
}

// load bbs item from server
void bbs::get_item(){
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int length;

    in >> length;
    qDebug()<<"get bbs item call" << QString::number(length);
    for(int i=0; i<length; i++)
    {
        bbsItem bbbsitem;
        in >> bbbsitem.id >> bbbsitem.name >> bbbsitem.title >> bbbsitem.content;
        bbsItems.append(bbbsitem);
    }
    qDebug()<<"before add bbs item";
    for(int i=0;i<length; i++){
        adbbsitem(this->bbsItems[i].title,bbsItems[i].content,bbsItems[i].name,QString::number(bbsItems[i].id));
    }
    qDebug()<<"after add bbs item";

}

// get item while other people post a new post.
void bbs::get_single_item(){
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    qDebug()<<"get_single_item called";
    bbsItem bbbsitem;
    in >> bbbsitem.id >> bbbsitem.name >> bbbsitem.title >> bbbsitem.content;
    adbbsitem(bbbsitem.title,bbbsitem.content,bbbsitem.name,QString::number(bbbsitem.id));

}
