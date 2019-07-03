#ifndef TCPSERVER_H
#define TCPSERVER_H
#include<QtNetwork/QTcpServer>
#include"clientsocket.h"
#include"database.h"
#include"constant.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);
    ~TcpServer();
public slots:
    void clientdisconnect( int &id);
    void sendmessage(const Tmpinfo &tmp);
    //添加其他的函数辅助sendmessage,也可以全部在sendmessage内部实现

private:
    // 当有新的连接时，会调用此函数。用于创建新的线程去控制socket通信
    void incomingConnection(qintptr socketDescriptor) ;
private:
    Tmpinfo m_tmp;
    Database m_database;
    // 在线用户列表
    QMap<int, ClientSocket*> m_userMap;
    // 在线用户状态
    QMap<int, int> m_userStatus;
};


#endif // TCPSERVER_H
