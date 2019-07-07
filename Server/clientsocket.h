#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include<QtNetwork/QTcpSocket>
#include"constant.h"
#include"database.h"

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket(QObject *parent = nullptr);
    ~ClientSocket();
    //将处理完的消息发送给客户端
    void sendmessage(const Tmpinfo &);

signals:
    //请求服务器在后台对通信消息进行处理
    void sendsignal(const Tmpinfo &tmp);
    //请求断开连接
    void deletesignal( int &id);

public slots:
    //接收消息并进行初步的判断和处理
    void receivemessage();
    //删除socket
    void deletesocket();

private:
    Database m_database;
    Tmpinfo m_tmp;
};
#endif // CLIENTSOCKET_H
