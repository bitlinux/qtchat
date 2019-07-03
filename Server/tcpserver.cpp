#include"tcpserver.h"

TcpServer::TcpServer(QObject *parent) :
    QTcpServer(parent)
{
    // 初始化
}

TcpServer::~TcpServer()
{
    //退出
}

//一个连接下线
void TcpServer::clientdisconnect(const int &id)
{
    //移除掉一个在线用户
    //当id为登录后掉线，正常调用移除用户语句，在登录之前掉线，id应该不为有效值，不进行无意义删除
    if(m_userMap.contains(id))
        m_userMap.remove(id);
    m_userStatus[id]=Offline;
    m_database.updateStatus(false,id);
    qDebug()<<tr("user %1 has exited !").arg(id);
    //通知其他人更改状态，数据库提前更改状态
}

//用来在后台处理接收到的消息并且进行转发
void TcpServer::sendmessage(const Tmpinfo &tmp)
{
    //每一次接收消息时要对m_tmp进行初始化!!!
    m_tmp={};
    m_tmp.request=tmp.request;
    //根据请求消息类型来判断做出什么回应
    switch(m_tmp.request)
    {
    case LOGIN:{
        m_tmp.login_info=tmp.login_info;
        m_tmp.socket=tmp.socket;
        m_tmp.reply=m_database.searchUserInUserInformation(m_tmp.login_info,m_tmp.main_info);
            if(m_tmp.reply==LOGIN_SUCCESS)
            {
                if(!m_userMap.contains(m_tmp.login_info.m_userID))
                {
                    m_userMap.insert(m_tmp.login_info.m_userID,m_tmp.socket);
                }
                m_userStatus[m_tmp.login_info.m_userID]=Online;
            }
            else {
                m_userStatus[m_tmp.login_info.m_userID]=Offline;
            }
        qDebug()<<"online user size: "<<m_userMap.size();
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case FORGET_PASSWORD_PROBLEM:{
        m_tmp.login_info=tmp.login_info;
        m_tmp.reply=m_database.searchProblemInUser(m_tmp.login_info,m_tmp.user);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case REGISTER:{
        m_tmp.user=tmp.user;
        m_tmp.reply=m_database.giveidnumber(m_tmp.user,m_tmp.user);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case CHECK_ANSWER:{
        m_tmp.user=tmp.user;
        m_tmp.reply=m_database.checkanswer(m_tmp.user);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case CHANGE_PASSWORD:{
        m_tmp.login_info=tmp.login_info;
        m_tmp.reply=m_database.changepassword(m_tmp.login_info);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case ADD_FRIEND:{
        m_tmp.talk=tmp.talk;
        m_tmp.reply=m_database.requestfriend(m_tmp.talk);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case AGREE_FRIEND:{
        m_tmp.talk=tmp.talk;
        m_tmp.reply=m_database.agreefriendrequest(m_tmp.talk,m_tmp.user);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case REFUSE_FRIEND:{
        m_tmp.talk=tmp.talk;
        m_tmp.reply=m_database.refusefriendrequest(m_tmp.talk);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case TALK:{
        m_tmp.talk=tmp.talk;
        m_tmp.reply=m_database.talktofriend(m_tmp.talk);
        if(m_userMap.contains(m_tmp.talk.receive_id))
        {
            m_tmp.reply=TALK;
            m_userMap[m_tmp.talk.receive_id]->sendmessage(m_tmp);
        }
        break;
    }
    case CHECK_MESSAGE:{
        m_tmp.talk=tmp.talk;
        m_tmp.reply=m_database.search_talk_message(m_tmp.talk,m_tmp.history);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case MESSAGE_RECORD:{
        m_tmp.talk=tmp.talk;
        m_tmp.reply=m_database.search_history_document(m_tmp.talk,m_tmp.history);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case CREATE_FLOCK:{
        m_tmp.flock=tmp.flock;
        m_tmp.reply=m_database.create_new_flock(m_tmp.flock);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case GET_FLOCK_MEMBERS:{
        m_tmp.flock=tmp.flock;
        m_tmp.reply=m_database.get_all_flock_member(m_tmp.flock,m_tmp.flocks_member);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case FLOCK_ADD_MEMBER:{
        m_tmp.flock_member=tmp.flock_member;
        m_tmp.reply=m_database.flock_add_member(m_tmp.flock_member);
        tmp.socket->sendmessage(m_tmp);
        break;

    }
    case CHANGE_FLOCK_NAME:{
        m_tmp.flock=tmp.flock;
        m_tmp.reply=m_database.change_flock_name(m_tmp.flock);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case CHANGE_INFORMATION:{
        m_tmp.user=tmp.user;
        m_tmp.reply=m_database.change_user_name(m_tmp.user);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    case TALK_FLOCK:{
        m_tmp.flock_talk=tmp.flock_talk;
        m_tmp.reply=m_database.send_flock_message(m_tmp.flock_talk,m_tmp.flocks_member);
        int len=m_tmp.flocks_member.size();
        //qDebug()<<len;
        for(int i=0;i<len;i++)
        {
            if(m_userMap.contains(m_tmp.flocks_member[i].user_id))
            {
                m_tmp.reply=TALK_FLOCK;
                m_userMap[m_tmp.flocks_member[i].user_id]->sendmessage(m_tmp);
            }
        }
        break;
    }
    case CHECK_FLOCK_MESSAGE:{
        m_tmp.flock=tmp.flock;
        m_tmp.reply=m_database.send_last_message_in_flock(m_tmp.flock,m_tmp.flock_history);
        tmp.socket->sendmessage(m_tmp);
        break;
    }
    default:
    {
        break;
    }
    }
}
//服务器和新的客户端建立连接
void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    ClientSocket *clientSocket = new ClientSocket(this);
    clientSocket->setSocketDescriptor(socketDescriptor);
    connect(clientSocket,SIGNAL(deletesignal(const int &)),this,SLOT(clientdisconnect(const int &)));
    connect(clientSocket,SIGNAL(sendsignal(const Tmpinfo &)),this,SLOT(sendmessage(const Tmpinfo &)));
    qDebug()<<"new client ip address: "<<clientSocket->peerAddress().toString();
    qDebug()<<"new client port: "<<clientSocket->peerPort();
}

