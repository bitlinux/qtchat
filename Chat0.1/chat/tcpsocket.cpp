#include"tcpsocket.h"
#include<QtNetwork>
#include<QtWidgets/QMessageBox>
#include<QHostAddress>
QHostAddress tcpsocket::s_hostAddress=QHostAddress("172.20.10.5");
int tcpsocket::s_hostPort=1234;


tcpsocket::tcpsocket(QObject *parent)
    :QTcpSocket (parent)
{
    m_isConnected=false;
    linkSignalWithSlot();
}


// 申请进行连接

void tcpsocket::requestConnect()
{
    if(!m_isConnected)
    {
        abort();
        connectToHost(tcpsocket::s_hostAddress,(unsigned short)tcpsocket::s_hostPort);
    }
}
//查看是否连接
bool tcpsocket::isConnected()
{
    return m_isConnected;
}

QString tcpsocket::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
    {
       if(address.protocol() == QAbstractSocket::IPv4Protocol) //我们使用IPv4地址
        {
           if(address.toString()!="127.0.0.1")
                return address.toString();
        }
    }
    return "";
}

QString tcpsocket::getCurrentDateTime()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();

    return QString("%1  %2").arg(date.toString(Qt::ISODate))
        .arg(time.toString(Qt::ISODate));
}

void tcpsocket::connectionClosed()
{
    m_isConnected=false;
    qDebug("连接断开");
}

void tcpsocket::connectionCreate()
{
    m_isConnected=true;
}

void tcpsocket::readtype()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_8);
    int type;
    in >> type;
    qDebug() << "tcpsocket_in_type" << type;
    emit send_type(type);
}

void tcpsocket::dispalyError(QAbstractSocket::SocketError socketError)
{
    m_isConnected = false;
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        emit showConnectionStatus(tr("RemoteHostClosedError"));
        break;
    case QAbstractSocket::HostNotFoundError:
        emit showConnectionStatus(tr("HostNotFoundError"));
        QMessageBox::information(nullptr, tr("IM Client"),
                                 tr("This host was not found.Please check the"
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        emit showConnectionStatus(tr("ConnectionRefusedError"));
        QMessageBox::information(nullptr, tr("IM Client"),
                                 tr("The connection was refused by the peer."
                                    "Make sure the IM server is running,"
                                    "and check that the host name and port"
                                    "settings are correct."));
        break;
    default:
        emit showConnectionStatus(tr("ERROR: %1.").arg(errorString()));
        QMessageBox::information(nullptr, tr("IM Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(errorString()));
    }
}

void tcpsocket::linkSignalWithSlot()
{
    connect(this, SIGNAL(connected()), this, SLOT(connectionCreate()));
    connect(this, SIGNAL(disconnected()), this, SLOT(connectionClosed()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(dispalyError(QAbstractSocket::SocketError)));
    connect(this,SIGNAL(readyRead()),this,SLOT(readtype()));
}
