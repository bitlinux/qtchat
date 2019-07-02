#include"clientsocket.h"
#include<QDataStream>

ClientSocket::ClientSocket(QObject *parent):
    QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(receivemessage()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deletesocket()));
    m_tmp.socket=this;
}

ClientSocket::~ClientSocket()
{

}


//接收用户发给服务器的消息并且分类处理
void ClientSocket::receivemessage()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_8);
    in>>m_tmp.request;
    qDebug()<<"receive message type: "<<m_tmp.request;
    //根据不同的消息类型给通信消息体赋值
    //注意，由于涉及到更新服务器在线数据库和用户列表的问题，需要在登录之后的操作中传递id号以区别登录用户和未登录用户
    switch(m_tmp.request)
    {
    case LOGIN: {
                    in>>m_tmp.ID>>m_tmp.login_info.m_userID>>m_tmp.login_info.m_password;
                    break;
                    }
    case REGISTER:{
        in>>m_tmp.user.nickname>>m_tmp.user.password>>m_tmp.user.problem1>>m_tmp.user.answer1>>m_tmp.user.problem2>>m_tmp.user.answer2;
        break;
    }
    case FORGET_PASSWORD_PROBLEM:{
        in>>m_tmp.login_info.m_userID;
        break;
    }
    case CHANGE_PASSWORD:{
        in>>m_tmp.login_info.m_userID>>m_tmp.login_info.m_password;
        break;
    }
    case CHECK_ANSWER:{
        in>>m_tmp.user.id>>m_tmp.user.answer1>>m_tmp.user.answer2;
        break;
    }
    case ADD_FRIEND:{
        in>>m_tmp.talk.send_id>>m_tmp.talk.receive_id>>m_tmp.talk.message;
        break;
    }
   case AGREE_FRIEND:{
        in>>m_tmp.talk.send_id>>m_tmp.talk.receive_id;
        break;
    }
   case REFUSE_FRIEND:{
        in>>m_tmp.talk.send_id>>m_tmp.talk.receive_id;
        break;
    }
    case TALK:{
        in>>m_tmp.talk.send_id>>m_tmp.talk.receive_id>>m_tmp.talk.message;
        break;
    }
    case CHECK_MESSAGE:{
        in>>m_tmp.talk.receive_id>>m_tmp.talk.send_id;
        break;
    }
    default: {
        break;
    }
    }
    //给服务器发送信号，在后台进行进一步处理，操作数据库，并且将通信消息体进行适当的更改
    if(m_tmp.request!=QUIT)
        emit(sendsignal(m_tmp));
}

//根据服务器更改完后的消息体，给客户端按照不同响应类型发送消息
void ClientSocket::sendmessage(const Tmpinfo &tmp)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<tmp.reply;
    qDebug()<<"reply message: "<<tmp.reply;
    switch(tmp.reply)
    {
        case LOGIN_SUCCESS:
    {
        out<<tmp.main_info.myID<<tmp.main_info.myname<<tmp.main_info.friends<<tmp.main_info.groups<<tmp.main_info.notifications;
        break;
    }
    case FORGET_PASSWORD_PROBLEM_SUCCESS:
    {
        out<<tmp.user.problem1<<tmp.user.problem2;
        break;
    }
    case REGISTER_SUCCESS:{
        out<<QString::number(tmp.user.id);
        break;
    }
    case SEND_REQUEST_SUCCESS:{

        break;
    }
    case TALK:{
        out<<tmp.talk.send_id<<tmp.talk.message;
        break;
    }
    case HAVE_MESSAGE:{
        out<<tmp.talk.send_id<<tmp.history.size();
        int len=tmp.history.size();
        for(int i=0;i<len;i++)
        {
            out<<tmp.history[len-i-1];
        }
        break;
    }
    case NO_MESSAGE:{
        out<<tmp.talk.send_id;
        break;
    }
    default:
        break;
    }
    write(block);
}

//删除当前的socket
void ClientSocket::deletesocket()
{
    //qDebug()<<"delete socket! request type: "<<m_tmp.request;
    if(m_tmp.request==QUIT)
        emit deletesignal(m_tmp.login_info.m_userID);
    deleteLater();
}
