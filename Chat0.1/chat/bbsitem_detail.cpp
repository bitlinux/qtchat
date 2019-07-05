#include "bbsitem_detail.h"
#include "ui_bbsitem_detail.h"
#include "constant.h"
#include "QDebug"

bbsitem_detail::bbsitem_detail(QWidget *parent, tcpsocket *m, QString ibbs_id, QString poster_id, QString my_id, QString icontent, QString ititle, QString iposter_name,QString posttime) :
    QDialog(parent),
    ui(new Ui::bbsitem_detail)
{
    ui->setupUi(this);

    m_tcpsocket = m;
    this->bbs_id = ibbs_id;
    this->posterID = poster_id;
    this->myID = my_id;
    this->title = ititle;
    this->content = icontent;
    this->poster_name = iposter_name;
    this->postTime = posttime;

    qDebug()<< "detail myid"<<bbs_id;
    // set delete button if I am not the post owner, then hide delete button.
    if(poster_id != my_id){
        this->ui->Delete->setFlat(true);
        this->ui->Delete->setText("");
    }
    this->ui->time_label->setText(" Post by " + poster_name + " at " + postTime);
    this->ui->time_label->setStyleSheet("text-align:right;color:gray;");
    this->ui->title_label->setText(title);
    //set title style
    QFont ft;
    ft.setPointSize(20);
    this->ui->title_label->setFont(ft);
    this->ui->content->setText(content);

}

bbsitem_detail::~bbsitem_detail()
{
    delete ui;
}

// get contennt and return a QString
QString bbsitem_detail::getContent(){
    return ui->reply->toPlainText();
}

// send commit to server
void bbsitem_detail::on_buttonBox_accepted()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);

    out<<int(REPLY_BBS)<<this->myID.toInt()<<this->bbs_id.toInt()<<getContent();
    qDebug()<<REPLY_BBS<<this->myID.toInt()<<this->bbs_id.toInt()<<getContent();
    //qDebug()<<"request delete bbs";

    m_tcpsocket->write(block);
    this->close();
}


// send delete request to server
void bbsitem_detail::on_Delete_clicked()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<int(DELETE_BBS)<<this->bbs_id.toInt();
    qDebug()<<DELETE_BBS<<this->bbs_id.toInt();
    //qDebug()<<"request delete bbs";
    m_tcpsocket->write(block);
    this->close();
}

// Get bbs post reply history, signal is passed from mainwindow layer by layer.
void bbsitem_detail::get_reply_history(){
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_8);
    int reply_num;
    in >> reply_num;
    qDebug()<<reply_num;

    for(int i = 0; i<reply_num; i++){
        reply_history rph;
        in >> rph.name >> rph.content >> rph.time;
        this->historys.append(rph);
    }
    //QByteArray block;
    //QDataStream out(&block,QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_4_8);

    //out<<130;
    //qDebug()<<"130";
    //m_tcpsocket->write(block);
    for(int i = 0; i < reply_num; i++){
        QString line1;
        line1 = historys[i].time + historys[i].name + '\n' + historys[i].content + '\n';
        this->ui->comment->append(line1);
    }
}
