#include "server_message.h"
#include "tcpserver.h"
#include <QDateTime>
#include <QtWidgets/QMessageBox>

ServerMessage::ServerMessage(QObject *parent) :
    QObject(parent)
{
    //初始化信息

}

ServerMessage::~ServerMessage()
{
    //退出时删除的信息
}

//启动服务器，所有的服务从此开始
void ServerMessage::runServer()
{
    m_tcpserver=new TcpServer(this);
    if(!m_tcpserver->listen(QHostAddress("192.168.43.104"),1234))
    {
        qDebug()<<"run server fail";
        QMessageBox::information(nullptr,tr("error"),tr("cannot bind to address %1 port %2").arg(QHostAddress::Any).arg(1234));
        exit(EXIT_FAILURE);
    }
    qDebug()<<tr("server is running at ipAddress %1 port %2").arg(m_tcpserver->serverAddress().toString()).arg(m_tcpserver->serverPort());
    m_database.initdatabase();

}
