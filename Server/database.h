#ifndef DATABASE_H
#define DATABASE_H
#include"constant.h"
#include <QObject>
#include <QMap>

class QSqlQuery;
class QSqlDatabase;
class QDateTime;

class Database : public QObject
{
    Q_OBJECT
public:
    Database(QObject *parent = nullptr);

    ~Database();
    //建立连接
    bool createconnection();
    //数据库初始化
    bool initdatabase();
    //搜索用户，在用户信息数据库里
    int searchUserInUserInformation(const LoginInfo &,MainWindowInfo &);
    //更新用户数据库的信息，更改在线状态
    bool updateStatus(bool status,const int &id);
    //传递两个密保问题
    int searchProblemInUser(const LoginInfo &,Userinfo &);
    //分配ID
    int giveidnumber( Userinfo&,Userinfo &);
    //修改密码
    int changepassword(const LoginInfo&);
    //检查密保问题答案是否正确
    int checkanswer( Userinfo&);
    //将申请好友的消息存入申请好友数据表
    int requestfriend( UserTalkinfo&);
    //同意好友申请
    int agreefriendrequest( UserTalkinfo&,Userinfo &);
    //拒绝好友申请
    int refusefriendrequest( UserTalkinfo&);
    //将通信消息加入数据库
    int talktofriend( UserTalkinfo&);
    //查询两个聊天好友的历史消息
    int search_talk_message( UserTalkinfo&, QVector<UserTalkinfo> &);
private:
    //检查SQL语句的正确性
    void errorSQLOrder(QSqlQuery query, QString mark);
    //创建数据库表格
    void createTable();

private:
    QSqlDatabase *m_database;
};

#endif // DATABASE_H
