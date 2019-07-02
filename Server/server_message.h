#ifndef SERVER_MESSAGE_H
#define SERVER_MESSAGE_H
#include <QObject>
#include"database.h"
class TcpServer;

class ServerMessage : public QObject
{
    Q_OBJECT
public:
    ServerMessage(QObject *parent = nullptr);
    ~ServerMessage();
    void runServer();  //启动服务器

private:
    TcpServer *m_tcpserver;
    Database  m_database;
 };


#endif // SERVER_MESSAGE_H
