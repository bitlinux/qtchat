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
    case MESSAGE_RECORD:{
        in>>m_tmp.talk.receive_id>>m_tmp.talk.send_id;
        break;
    }
    case CREATE_FLOCK:{
        in>>m_tmp.flock.creator_id>>m_tmp.flock.flock_name;

        break;
    }
    case GET_FLOCK_MEMBERS:{
        in>>m_tmp.flock.flock_id;
        break;
    }
    case FLOCK_ADD_MEMBER:{
        in>>m_tmp.flock_member.flock_id>>m_tmp.flock_member.user_id;
        break;
    }
    case CHANGE_FLOCK_NAME:{

        in>>m_tmp.flock.flock_id>>m_tmp.flock.flock_name;
        break;
    }
    case CHANGE_INFORMATION:{
        in>>m_tmp.user.id>>m_tmp.user.nickname;
        break;
    }
    case TALK_FLOCK:{
        in>>m_tmp.flock_talk.send_id>>m_tmp.flock_talk.flock_id>>m_tmp.flock_talk.message;
        break;
    }
    case CHECK_FLOCK_MESSAGE:{
        qDebug()<<"check flock message";
        in>>m_tmp.flock.flock_id;
        break;
    }
    case SEND_FILE_TO_PEER:{
        qDebug()<<"send file to peer";
        in>>m_tmp.talk.send_id>>m_tmp.talk.receive_id>>m_tmp.talk.message>>m_tmp.talk.bit;
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
    case HAVE_MESSAGE_RECODRD:{
        out<<tmp.talk.send_id<<quint32(0)<<tmp.history.size();
        int len=tmp.history.size();
        for(int i=0;i<len;i++)
        {
            out<<tmp.history[i].send_id<<tmp.history[i].message<<tmp.history[i].send_time;
            //qDebug()<<tmp.history[i].send_id<<tmp.history[i].message<<tmp.history[i].send_time;
        }
        out.device()->seek(2*sizeof(int));
        out << quint32(block.size() - sizeof(quint32)-2*sizeof(int));
        break;
    }
    case NO_MESSAGE_RECORD:{
        out<<QString::number(tmp.talk.send_id);
        break;
    }
    case CREATE_FLOCK_SUCCESS:{
        out<<tmp.flock.flock_id;
        break;
    }
    case GET_FLOCK_MEMBERS_SUCCESS:{
        //qDebug()<<"get flock member success!";
        out<<tmp.flock.flock_id<<tmp.flocks_member.size();
        for(int i=0;i<tmp.flocks_member.size();i++)
        {
            out<<tmp.flocks_member[i].user_id<<tmp.flocks_member[i].loginStatus;
        }
        break;
    }
    case GET_FLOCK_MEMBERS_FAIL:{
        //qDebug()<<"get flock member fail";
        out<<tmp.flock.flock_id;
        break;
    }
    case ADD_FLOCK_SUCCESS:{
        out<<tmp.flock_member.flock_id;
        break;
    }
    case ADD_FLOCK_FAIL:{
        out<<tmp.flock_member.flock_id;
        break;
    }
    case CHANGE_FLOCK_NAME_SUCCESS:{
        out<<tmp.flock.flock_id<<tmp.flock.flock_name;
        break;
    }
    case CHANGE_FLOCK_NAME_FAIL:{
        out<<tmp.flock.flock_id;
        break;
    }
    case CHANGE_INFORMATION_SUCCESS:{
        out<<tmp.user.nickname;
        break;
    }
    case TALK_FLOCK:{
        out<<tmp.flock_talk.flock_id<<tmp.flock_talk.send_id<<tmp.flock_talk.message<<tmp.flock_talk.send_time.toString("yyyy-MM-dd hh:mm:ss");
        break;
    }
    case NO_FLOCK_MEMBER:{
        out<<tmp.flock.flock_id;
        break;
    }
    case HAVE_FLOCK_MESSAGE:{
        //qDebug()<<"have flock";
        out<<tmp.flock.flock_id<<tmp.flock_history.size();
        int len=tmp.flock_history.size();
        for(int i=0;i<len;i++)
        {
            out<<tmp.flock_history[len-1-i].send_id<<tmp.flock_history[len-1-i].message<<tmp.flock_history[len-1-i].send_time.toString("yyyy-MM-dd hh:mm:ss");
        }
        break;
    }
    case SEND_FILE_TO_PEER:{
        out<<tmp.talk.send_id<<tmp.talk.message<<tmp.talk.bit<<tmp.talk.send_time;
        break;
    }
    case CHANGE_STATUE:{
        out<<tmp.login_info.m_userID;
        break;
    }
    case NEW_NOTI_FRIEND:{
        out<<tmp.talk.send_id<<tmp.talk.message<<tmp.talk.send_time<<tmp.user.nickname;
        break;
    }
    case FRESH_FRIEND_LIST:{
        out<<tmp.user.id<<tmp.user.nickname<<tmp.user.status;
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
    if(m_tmp.request==QUIT)
        emit deletesignal(m_tmp.login_info.m_userID);
    deleteLater();
}
