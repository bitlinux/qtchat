#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include<QTcpSocket>


class tcpsocket: public QTcpSocket
{
      Q_OBJECT
public:
    tcpsocket(QObject *parent=nullptr);
    // 请求连接
    void requestConnect();
    // 是否连接
    bool isConnected();

    // 获取ip
    static QString getIP();
    //获取当前的日期和时间
    static QString getCurrentDateTime();

    static QHostAddress s_hostAddress;
    static int s_hostPort;
signals:
    void showConnectionStatus(const QString &, bool isLogin = false);
    void send_type(int &type);
private slots:
    // 连接被客户端关闭
    void connectionClosed();
    // 连接创建
    void connectionCreate();
    // 显示错误
    void dispalyError(QAbstractSocket::SocketError);

    void readtype();
private:
    // 链接信号与槽
    void linkSignalWithSlot();


    bool m_isConnected;

};


#endif // TCPSOCKET_H
