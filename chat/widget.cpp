#include "widget.h"
#include <QtWidgets/QTextBrowser>
#include <QtNetwork>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    label =new QLabel(tr("dowload"));
    label1 =new QLabel(tr("upload"));
    label2 =new QLabel(tr("other"));
    lb=new QLabel("IP:");
    lb1=new QLabel("PORT:");
    lb2=new QLabel(tr("Process:"));
    pb=new QPushButton(tr("dowload"));
    pb->setEnabled(false);
    pb1=new QPushButton(tr("connect"));
    pb2=new QPushButton(tr("fresh filelist"));
    pb2->setEnabled(false);
    pb3=new QPushButton(tr("clear"));
    pb3->setEnabled(false);
    pb4=new QPushButton(tr("open file"));
    pb4->setEnabled(false);
    pb5=new QPushButton(tr("upload"));
    pb5->setEnabled(false);
    te1=new QTextEdit;
    le=new QLineEdit;  //输入IP信息
    le->setText("127.0.0.1");
    le1=new QLineEdit;  //输入端口信息
    le1->setText("8888");
    le2=new QLineEdit;  //输入download文件名
    le3=new QLineEdit;//显示要上传文件的绝对路径
    pgb=new QProgressBar; //进度条

    lb3=new QLabel(tr("FileList:"));
    te2=new QTextBrowser;

    //QHBoxLayout水平布局
    QHBoxLayout *hbox=new QHBoxLayout;//IP label，IP QLineEdit，PORT label，PORT QLineEdit，connect QPushButton
    hbox->addWidget(lb);
    hbox->addWidget(le);
    hbox->addWidget(lb1);
    hbox->addWidget(le1);
    hbox->addWidget(pb1);

    QHBoxLayout *hbox1=new QHBoxLayout;//download 文件名 QLineEdit，download QPushButton
    hbox1->addWidget(le2);
    hbox1->addWidget(pb);

    QHBoxLayout *hbox2=new QHBoxLayout;  //open file QPushButton,upload QPushButton
    hbox2->addWidget(pb4);
    hbox2->addWidget(pb5);

    //QVBoxLayout垂直布局
    QVBoxLayout *vbox1=new QVBoxLayout;
    vbox1->addWidget(lb2);//Process QLabel
    vbox1->addWidget(pgb);//进度条 QProgressBar
    vbox1->addWidget(te1);//显示各种信息 QTextEdit

    vbox1->addWidget(lb3);
    vbox1->addWidget(te2);


    QVBoxLayout *vbox2=new QVBoxLayout;
    vbox2->addWidget(label);//增加download QLabel
    vbox2->addLayout(hbox1);//设置水平布局hbox1,下载文件名标签框和下载按钮
    vbox2->addWidget(label1);//增加upload QLabel
    vbox2->addWidget(le3);//增加 要上传文件的绝对路径 的QLineEdit
    vbox2->addLayout(hbox2);//增加水平布局hbox2，打开文件和上传按钮
    vbox2->addWidget(label2);//增加other QLabel
    vbox2->addWidget(pb2);//增加get dowload filelist按钮
    vbox2->addWidget(pb3);//增加clear按钮

    QHBoxLayout *hbox3=new QHBoxLayout;//设置水平布局
    hbox3->addLayout(vbox1);//设置左侧的布局，进度条，信息等
    hbox3->addLayout(vbox2);//设置右侧的布局，下载，上传，other

    QVBoxLayout *vbox3=new QVBoxLayout;//设置垂直布局
    vbox3->addLayout(hbox);//上面是IP，port，connect一大行
    vbox3->addLayout(hbox3);//下面是message，download一大堆

    setLayout(vbox3);//布局生效
    tcp= new QTcpSocket;
    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(connect_ser()));//connect
    connect(pb,SIGNAL(clicked(bool)),this,SLOT(send_data()));//download
    //connect(pb2,SIGNAL(clicked(bool)),this,SLOT(show_file()));//get dowload filelist

    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(fresh()));

    connect(pb3,SIGNAL(clicked(bool)),te1,SLOT(clear()));//clear
    connect(pb4,SIGNAL(clicked(bool)),this,SLOT(open_file()));//open file
    connect(pb5,SIGNAL(clicked(bool)),this,SLOT(up_file()));//upload
    connect(le3,SIGNAL(textChanged(QString)),this,SLOT(up_lock()));

    dir=new QDir(".");
    if(!dir->cd("file"))
    {
        dir->mkdir("./file");
    }
}

Widget::~Widget()
{

}

void Widget::connect_ser()
{
    tcp->connectToHost(QHostAddress(le->text()), le1->text().toInt());
    connect(tcp, SIGNAL(connected()), this, SLOT(show_connected()));
    connect(tcp,SIGNAL(bytesWritten(qint64)),this,SLOT(gosend()));


}

void Widget::show_connected()
{

    te1->setText(tr("connected!"));
    pb->setEnabled(true);
    pb2->setEnabled(true);
    pb3->setEnabled(true);
    pb4->setEnabled(true);
    connect(tcp,SIGNAL(readyRead()),this,SLOT(recv_data()));
}
void Widget::send_data()
{
    tcp->write("get_file ");
    filename=le3->text();
}
void Widget::recv_data()
{
    if(flag==2)//上传文件准备已完成，flag值为2
    {
        char buf[100];
        memset(buf,0,sizeof(buf));
        len= tcp->bytesAvailable();
        tcp->read(buf,len);
        if(strcmp(buf,"OK ")==0)
        {
            file=new QFile(filename);
            te1->append(filename);
            if(!file->open(QIODevice::ReadWrite))
            {
                tcp->write("up false!");
                te1->append("upload failed!");
                return ;
            }
            data_total=file->size()+sizeof(qint64);
            pgb->clearFocus();
            pgb->setRange(0,data_total);
            pgb->setValue(0);
            upload_file();
            flag=3;//上传成功，值为3
        }

    }
    else if(flag==1)
    {
        QDataStream in(tcp);
        qDebug()<<data_get;
        if(data_get==0)
        {
            in>>data_total;
            data_get=sizeof(qint64);
            pgb->clearFocus();
            pgb->setRange(0,data_total);
            pgb->setValue(0);
        }
        if(data_get<data_total)
        {
            data_get=data_get+tcp->bytesAvailable();
            file_data=tcp->readAll();
            get_file();
            pgb->setValue(data_get);
        }
        if(data_get==data_total)
        {
            te1->append(tr("dowload successed!"));
            file->close();
            file->destroyed();
            fp=0;
            flag=0;
            data_get=0;
            data_total=0;
        }
    }
    else if(flag==0)//flag初始值为0
    {
        char buf[100];
        memset(buf,0,sizeof(buf));
        len= tcp->bytesAvailable();
        tcp->read(buf,len);
        if(strcmp(buf,"get_file ")==0)
        {
            QString str =le2->text();
            filename=le2->text();//读取输入的download文件名 lineedit
            tcp->write(str.toStdString().c_str(),str.length());
            flag=1;//下载准备工作完成，值置为1
        }
        else if(strcmp(buf,"up_file ")==0)
        {
            QStringList list =filename.split("/");//用"/"分割路径得到一个列表
            QString str=list.last();//获取文件名
            tcp->write(str.toStdString().c_str(),str.length());
            flag=2;//上传准备工作完成，值置为2
        }
        else
            te1->append(buf);
    }

}

void Widget::show_file()
{
    tcp->write("get_filename ");
}

void Widget::open_file()
{
    filename=QFileDialog::getOpenFileName(this,tr("open file"),"./file/");
    if(filename.isEmpty())
    {
        return;
    }
    le3->setText(filename);
}

void Widget::get_file()
{
    if(fp==0)
    {
        QString buff={"./file/"};
        buff.append(filename);
        file=new QFile(buff);
        te1->append(buff);
        if(!file->open(QIODevice::ReadWrite|QIODevice::Truncate))
        {
            te1->append(tr("dowload failed!"));
            return ;
        }
        fp=1;
    }
    file->write(file_data);
    file_data.resize(0);

}

void Widget::upload_file()
{
    QDataStream dts(&file_data1,QIODevice::ReadWrite);
    file_data.clear();
    data_get=data_total;
    dts<<qint64(0);
    dts.device()->seek(0);
    int sz=file_data1.size();
    sz=sz+file->size();
    dts<<(qint64)(sz);
    qDebug()<<file->size();
    data_get=sz-tcp->write(file_data1);

}

void Widget::up_file()
{
    tcp->write("up_file ");
}

void Widget::gosend()
{
    if(flag==3)
    {
        if(data_get>0)
        {
            file_data=file->read(qMin(data_get,data_local));
            data_get=data_get-tcp->write(file_data);
            pgb->setValue(data_total-data_get);
        }
        else
        {

            data_get=0;
            data_total=0;
            file->close();
            file->destroyed();
            flag=0;
            te1->append(tr("upload successed!"));
        }
    }
}

void Widget::up_lock()
{
    if(le3->text()!="")
    {
        pb5->setEnabled(true);
    }
    else
    {
        pb5->setEnabled(false);
    }
}

void Widget::replyFinished(QNetworkReply *reply)
{
    QString all = reply->readAll();
    te2->setText(all);
    reply->deleteLater();
}

//void Widget::on_pb2_clicked()
void Widget::fresh()
{
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://149.248.60.148/tcp_server/file/")));//文件服务器地址
    //manager->deleteLater();
}
