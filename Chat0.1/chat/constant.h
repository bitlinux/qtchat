#ifndef CONSTANT_H
#define CONSTANT_H
#include <QDateTime>
#include <QVector>
#include<QMap>
#include <QString>
#include <QObject>
#include<QDataStream>

static const QString Flock_Name_Default = QString(QObject::tr("New Flock"));
static const QString Nick_Name_Default=QString(QObject::tr("New User"));
class ClientSocket;

struct ServerNode
{
    QString ipAddress;			//服务器地址
    int port;					//服务器端口
    ServerNode()
    {	port = 1234; }
};
//用户的登录状态
enum LoginStatus{
    Online =1,
    Offline=2
};

//群成员身份
enum FlockStatus
{
    FLOCK_HOST = 0,    // 群主
    FLOCK_ADMAIN = 1,  // 群管理员
    FLOCK_MEMBER = 2   // 群成员
};
//朋友消息
struct FriendInfo
{
    QString ID;
    QString name;
    //QString photo;
    QString isonline;
    friend QDataStream & operator<< (QDataStream &out,const FriendInfo &fri)
    {
        out << fri.ID << fri.name << fri.isonline;
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in, FriendInfo &fri)
    {
        in >> fri.ID >> fri.name >> fri.isonline;
        return in;
    }
};

struct GroupInfo
{
    QString ID;
    QString name;
    //QString photo;

    friend QDataStream & operator<< (QDataStream &out,const GroupInfo &gro)
    {
        out << gro.ID << gro.name;
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in, GroupInfo &gro)
    {
        in >> gro.ID >> gro.name;
        return in;
    }
};

struct NotiInfo
{
    QString ID;
    QString name;
    //QString photo;
    QString message;
    QString time;

    friend QDataStream & operator<< (QDataStream &out,const NotiInfo &noti)
    {
        out << noti.ID << noti.name << noti.message << noti.time;
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in, NotiInfo &noti)
    {
        in >> noti.ID >> noti.name >> noti.message >> noti.time;
        return in;
    }
};

struct MainWindowInfo
{
    QString myID;
    QString myname;
    //QString photo;
    QVector<FriendInfo> friends;
    QVector<GroupInfo> groups;
    QVector<NotiInfo> notifications;


    friend QDataStream & operator<< (QDataStream &out, QVector<FriendInfo> &fris)
    {
        int len = fris.size();
        out << QString::number(len);
        for (int i = 0; i < len; i++)
        {
            out << fris[i];
        }
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in, QVector<FriendInfo> &fris)
    {
        QString len;
        in >> len;
        for (int i = 0; i < len.toInt(); i++)
        {
            in >> fris[i];
        }
        return in;
    }
    friend QDataStream & operator<< (QDataStream &out, QVector<GroupInfo> &group)
    {
        int len = group.size();
        out << QString::number(len);
        for (int i = 0; i < len; i++)
        {
            out << group[i];
        }
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in, QVector<GroupInfo> &group)
    {
        QString len;
        in >> len;
        for (int i = 0; i < len.toInt(); i++)
        {
            in >> group[i];
        }
        return in;
    }
    friend QDataStream & operator<< (QDataStream &out, QVector<NotiInfo> &noti)
    {
        int len = noti.size();
        out << QString::number(len);
        for (int i = 0; i < len; i++)
        {
            out << noti[i];
        }
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in, QVector<NotiInfo> &noti)
    {
        QString len;
        in >> len;
        for (int i = 0; i < len.toInt(); i++)
        {
            in >> noti[i];
        }
        return in;
    }

};

// 消息类型
enum MessageType
{
    /***********************client to server************************/
    LOGIN,                      // 登录
    REGISTER,                   // 注册

    FORGET_PASSWORD_PROBLEM, // get problems
    FORGET_PASSWORD_PROBLEM_SUCCESS,
    FORGET_PASSWORD_PROBLEM_FAIL,
    CHECK_SUCCESS,
    CHECK_FAIL,
    CHECK_ANSWER,

    GET_QUESTION_ANSWER,    // 获取密保问题以及答案
    GET_QUESTION_ANSWER_SUCCESS,
    GET_QUESTION_ANSWER_FAIL,


    CHECK_MESSAGE,              // 检查有无给自己的信息（登录时检查）

    GET_ALL_FRIENDS,            // 获取所有好友信息
    GET_ALL_FLOCKS,             // 获取所有群信息
    GET_FLOCK_MEMBERS,          // 获取群成员

    TALK,				// 发送对话

    ADD_FRIEND,                 // 添加好友
    FRIEND_EXIST,

    ADD_FLOCK,                   // 用户加群

    FLOCK_ADD_MEMBER,            // 群加用户

    GET_FRIEND_INFORMATION,		// 获取好友信息
    DELETE_FRIEND,				// 删除好友
    GET_MYSELF_INFORMATION,		// 获取自己信息
    CHANGE_INFORMATION,			// 改变自己的信息
    CHANGE_REMARK,				// 改变（好友）备注
    CHANGE_PASSWORD,			    // 修改密码
    CHANGE_STATUE,				// 改变自身状态
    // 还有分组好友管理
    QUIT,						// 退出

    /***********************server to client************************/

    LOGIN_SUCCESS ,				// 登录成功
    LOGIN_FAIL,			        // 登录失败
    HAVE_LOGINED,				// 已经登录
    REGISTER_SUCCESS,	        // 注册成功
    REGISTER_FAIL,			    // 注册失败


    GET_ALL_FRIENDS_SUCCESS,    // 获取所有好友信息成功
    GET_ALL_FRIENDS_FAIL,       // 获取所有好友信息失败
    NO_FRIEND,                  // 没有好友
    GET_ALL_FLOCKS_SUCCESS,     // 获取所有群信息成功
    GET_ALL_FLOCKS_FAIL,        // 获取所有群信息失败
    NO_FLOCK,


    GET_FLOCK_MEMBERS_FAIL,           // 获取群成员失败
    GET_FLOCK_MEMBERS_SUCCESS,        // 获取群成员成功
    NO_FLOCK_MEMBER,                // 没有群成员

    NO_MESSAGE,				    // 没有信息
    HAVE_MESSAGE,				// 有信息
    HAVE_TALK_MESSAGE,          // 有聊天信息

    FRIEND_REQUESTED,			// 好友请求
    FRIEDN_NO_ACCOUNT,			// 没有这个用户名
    ALREAD_FRIENDS,			    // 回应好友请求

    GET_FRIEND_FAIL,
    GET_FRIEND_SUCCESS,			// 获得好友资料成功
    DELETE_FRIEND_FAIL,
    DELETE_FRIEND_SUCCESS,		// 删除好友成功
    GET_MYSELF_FAIL,
    GET_MYSELF_SUCCESS,		    // 获得自己详细资料成功
    CHANGE_INFORMATION_FAIL,
    CHANGE_INFORMATION_SUCCESS,	// 改变自身资料成功

    CHANGE_REMARK_FAIL,             // 修改备注失败
    CHANGE_REMARK_SUCCESS,		// 修改备注成功

    OLD_PWD_IS_WRONG,			// 旧密码是错的
    CHANGE_PWD_FAIL,              // 修改密码失败
    CHANGE_PWD_SUCCESS,			// 修改密码成功

    /***********************client to client************************/

    REQUEST_FRIEND,	     // 请求添加好友
    SEND_REQUEST_FAIL,
    SEND_REQUEST_SUCCESS,
    AGREE_FRIEND,	     // 同意好友请求
    REFUSE_FRIEND,		 // 不同意好友请求
    ADD_FRIEND_FAIL,      // 添加好友失败
    ADD_FRIEND_SUCCESS,   // 添加好友成功
    END_ADD_FRIEND,	     // 好友添加结束
    BE_DELETED,		     // 自己被好友删除了

    MESSAGE,				 // 普通信息
    TALK_MESSAGE,         // 聊天信息

    REQUEST_FLOCK,   // 用户请求加入群
    FLOCK_AGREE,    // 群主同意用户加入
    FLOCK_REFUSE,   // 群主拒绝用户加入
    ADD_FLOCK_FAIL,             // 加入群失败
    ADD_FLOCK_SUCCESS,          // 加入群成功
    NEW_FLOCK_MEMBER,           // 新成员入群
    LEAVE_FLOCK_MEMBER,


    FLOCK_REQUEST,  // 群主请求用户加入群
    AGREE_FLOCK,    // 用户同意加入群
    REFUSE_FLOCK,   // 用户拒绝加入群


    CREATE_FLOCK,               // 创建群
    CREATE_FLOCK_FAIL,
    CREATE_FLOCK_SUCCESS,


    DROP_FLOCK,                 // 解散群
    DROP_FLOCK_FAIL,            // 解散群失败
    DROP_FLOCK_SUCCESS,         // 解散群成功


    LEAVE_FLOCK,              // 退出群
    LEAVE_FLOCK_SUCCESS,      // 退出群成功
    LEAVE_FLCCK_FAIL,         // 退出群失败


    CHANGE_FLOCK,               // 修改群信息
    CHANGE_FLOCK_SUCCESS,
    CHANGE_FLOCK_FAIL,

    CHANGE_FLOCK_REMARK,             // 修改群成员备注
    CHANGE_FLOCK_REMARK_FAIL,
    CHANGE_FLOCK_REMARK_SUCCESS,

    TALK_FLOCK,               // 群对话

    REQUEST_VIDEO,
    REFUSE_VIDEO,
    END_VIDEO,
    REQUEST_VOICE,
    AGREE_VOICE,
    REFUSE_VOICE,
    END_VOICE,
    REQUEST_FILE,
    AGREE_FILE,
    REFUSE_FILE,
    END_FILE,

    GET_HISTORY_MESSAGE,   //获取历史记录
    GET_HISTORY_MESSAGE_SUCCESS,
    GET_HISTORY_MESSAGE_FAIL
};

//用户信息
struct Userinfo{
    QString image;  //头像
    int id;   //账号
    QString nickname;  //昵称
    QString password;  //密码
    QString problem1; //密保问题1
    QString problem2; //密保问题2
    QString answer1;  //回答1
    QString answer2; //回答2
    int status; //在线状态
    QDateTime reg_time; //注册时间
    bool sex; //用户性别 true=man false=women
    Userinfo()
    {
        status=Offline;
    }
};

//群信息
struct Flockinfo{
    int flock_id; //群id
    int creator_id;//群主id
    QString flock_name; //群名称
    QDateTime create_time;//创建时间
    int user_num;//用户数量
};

// 群成员信息
struct FlockMember
{
    int flock_id;     // 群ID
    int user_id;      // 用户ID
    int loginStatus;     // 用户登录状态
    QString remark;      // 用户群名片
    int flockStatus;     // 用户身份
    QDateTime joinDate;  // 加入时间
};


// 用户登录消息
struct LoginInfo
{
    int m_userID;
    QString m_password;
    int m_status;

    LoginInfo()
    {	m_status =Offline;	}
};

// 用户聊天消息
struct UserTalkinfo{
    int talk_id; //聊天记录id
    int send_id; //发送者id
    int receive_id; //接受者id
    int type; //消息类型:普通聊天，加好友，删除好友，发文件，下载文件
    QString message;   //聊天内容
    QDateTime send_time; //发送时间

    friend QDataStream & operator<< (QDataStream &out, const UserTalkinfo &uin)
    {
        out << uin.talk_id << uin.send_id << uin.receive_id << uin.type << uin.message << uin.send_time ;
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in,UserTalkinfo &uin)
    {

        in >>uin.talk_id >> uin.send_id >> uin.receive_id >> uin.type >> uin.message >> uin.send_time ;
        return in;
    }
    friend QDataStream & operator<< (QDataStream &out, QVector<UserTalkinfo> &userinfo)
    {
        int len = userinfo.size();
        out << QString::number(len);
        for (int i = 0; i < len; i++)
        {
            out << userinfo[i];
        }
        return out;
    }
    friend QDataStream & operator>> (QDataStream &in, QVector<UserTalkinfo> &userinfo)
    {
        QString len;
        in >> len;
        for (int i = 0; i < len.toInt(); i++)
        {
            in >> userinfo[i];
        }
        return in;
    }


};

//群聊消息
struct FlockTalkinfo{
    int flocktalk_id;//群聊天记录id
    int flock_id;//群id
    int send_id;//发送者id
    int type;//消息类型：普通聊天，退出群，编辑群名称，加入群
    QString message;//发送内容
    QDateTime send_time; //发送时间
};

//BBS消息
struct BBSinfo{
    int bbs_id; //帖子id号
    int user_id; //发送用户的id
    QString title;//标题
    QString content;//内容
    QDateTime publish_time;//发帖时间
};

//BBS回帖消息
struct BBSreply{
    int reply_id;//回帖id
    int bbs_id;//被回帖的bbs的id
    int user_id;//回帖用户的id
    QString text;//回帖的内容
    QDateTime reply_time;//回帖的时间
};

//保存通信过程的临时消息体
struct Tmpinfo{
    int request;//请求消息类型
    int reply;//回复消息类型

    QString ID;//代表用户ID的字符串
    ClientSocket *socket;//用于通信的socket
    MainWindowInfo main_info;//用于主窗口通信
    Userinfo user;//用户基本信息
    Flockinfo flock;//群基本信息
    FlockMember flock_member;//群成员基本信息
    LoginInfo login_info;//登录消息
    UserTalkinfo talk;//用户聊天消息
    FlockTalkinfo flock_talk;//群聊消息
    BBSinfo bbs_info;//bbs消息
    BBSreply reply_info;//bbs回复消息

    QVector<Userinfo> friends;//所有好友信息
    QVector<Flockinfo> flocks;//所有群信息
    QVector<FlockMember> flocks_member;//所有群成员信息
    QVector<UserTalkinfo> history;//用户聊天历史记录信息
    QVector<FlockTalkinfo> flock_history;//群聊历史记录信息
    QVector<BBSinfo> bbs_history;//bbs缓存消息
    QMap<QString,QVector<BBSreply>> reply_history;//所有bbs的所有回复消息
};

#endif // CONSTANT_H
