#include"database.h"
#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtWidgets/QMessageBox>
#include<QDateTime>
#include<QVariant>
#include<QDebug>
/*create table  */
static const QString CREATE_TABLE_USERINFO=
        "create table User("
        "id INT(10) NOT NULL , "
        "password VARCHAR(50) NOT NULL,"
        "problem1 VARCHAR(50) NOT NULL,"
        "answer1 VARCHAR(50) NOT NULL,"
        "problem2 VARCHAR(50) NOT NULL,"
        "answer2 VARCHAR(50) NOT NULL,"
        "nickname VARCHAR(50) NOT NULL,"
        "image VARCHAR(20) NOT NULL,"
        "reg_time DATETIME ,"
        "isonline BOOLEAN,"
        "sex BOOLEAN, PRIMARY KEY(id))DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_FRIEND=
        "create table Friend("
        "lefthand INT(10) NOT NULL,"
        "righthand INT(10) NOT NULL, PRIMARY KEY(lefthand,righthand))DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_FLOCK=
        "create table Flock("
        "flockID INT(15) NOT NULL PRIMARY KEY,"
        "flockCreator INT(10) NOT NULL,"
        "flockName VARCHAR(50) NOT NULL,"
        "UserNumber INT NOT NULL,"
        "BuildTime DATETIME)DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_FLOCK_MEMBER=
        "create table FlockMember("
        "flockID INT(15) NOT NULL,"
        "userID INT(10) NOT NULL,"
        "PRIMARY KEY(flockID,userID))DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_REQUEST_FRIEND=
        "create table RequestFriend("
        "requestID INT(10) NOT NULL, "
        "replyID INT(10) NOT NULL, "
        "message TEXT(100) NOT NULL,"
        "time DATETIME NOT NULL,"
        "pass INT(10) , PRIMARY KEY(requestID,replyID))DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_TALKINFO=
        "create table Talk("
        "talkID INT(20) PRIMARY KEY,"
        "sendID INT(10) NOT NULL,"
        "receiveID INT(10) NOT NULL,"
        "message BLOB ,"
        "time DATETIME )DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_FLOCKTALKINFO=
        "create table FlockTalk("
        "flockTalkID INT(20) PRIMARY KEY,"
        "flockID INT(15) NOT NULL,"
        "userID INT(10) NOT NULL,"
        "message TEXT,"
        "time DATETIME NOT NULL)DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_BBSINFO=
        "create table BBS("
        "bbsID INT(20) PRIMARY KEY,"
        "userID INT(15) NOT NULL,"
        "title TEXT(50),"
        "content TEXT(200),"
        "time DATETIME NOT NULL)DEFAULT CHARSET=utf8;";

static const QString CREATE_TABLE_BBSREPLY=
        "create table REPLY("
        "replyID INT(20) PRIMARY KEY,"
        "userID INT(15) NOT NULL,"
        "bbsID INT(20) DEFAULT 0,"
        "content TEXT(200),"
        "time DATETIME NOT NULL)DEFAULT CHARSET=utf8;";

//update table
static const QString UPDATE_STATUS_IN_USERINFORMATION_SQL =
        "update User set isonline = false ;";

static const QString  UPDATE_STATUS_IN_USERINFORMATION_BY_ID_SQL=
        "update User set isonline = ? where id = ? ;";

static const QString INSERT_INTO_USER=
        "insert into User(id,password,problem1,answer1,problem2,answer2,nickname,image,reg_time,isonline) values(?,?,?,?,?,?,?,?,?,?);";

static const QString CHANGE_PASSWORD_IN_USER=
        "update User set password=? where id=?;";

static const QString INSERT_REQUEST_FRIEND_IN_DB=
        "insert into RequestFriend  values(?,?,?,?,?);";

static const QString AGREE_FRIEND_REQUEST=
        "update RequestFriend set pass=1 where requestID=? and replyID=? ;";

static const QString ADD_FRIEND_IN_FRIEND=
        "insert into Friend values(?,?);";
static const QString UPDATE_NEW_FRIEND=
        "select User.id,User.nickname,User.isonline from User where id=?;";

static const QString REFUSE_FRIEND_REQUEST=
        "update RequestFriend set pass=-1 where requestID=? and replyID=?;";

static const QString ADD_MESSAGE_TO_TALK=
        "insert into Talk values(?,?,?,?,?);";

static const QString CREATE_NEW_FLOCK_ID=
        "select 1000000+count(*) from Flock;";

static const QString CREATE_NEW_FLOCK=
        "insert into Flock values(?,?,?,?,?);";

static const QString CREATE_NEW_FLOCK_MEMBER=
        "insert into FlockMember values(?,?);";

static const QString FLOCK_ADD_MEMBER_REQUEST=
        "insert into FlockMember values(?,?);";

static const QString CHANGE_FLOCK_NAME_IN_FLOCK=
        "update Flock set flockName=? where flockID=?;";

static const QString CHAGNE_USER_NAME=
        "update User set nickname=? where id=?;";

static const QString SEND_FLOCK_MESSAGE=
        "insert into FlockTalk values(?,?,?,?,?);";

static const QString SAVE_FILE_IN_DB=
        "insert into File values(?,?,?,?,?,?);";

static const QString ADD_NEW_RECORD_IN_BBS=
        "insert into BBS values(?,?,?,?,?);";

static const QString REPLY_TO_BBS=
        "insert into REPLY values(?,?,?,?,?);";

static const QString DELETE_BBS_IN_BBS=
        "delete from BBS where bbsID=?;";

static const QString DELETE_BBS_IN_REPLY=
        "delete from REPLY where bbsID=?;";

//find item

static const QString SEARCH_USER_IN_USERINFORMATION_SQL =
        "select * from User where (id = ? and password = ?);";

static const QString SEARCH_PROBLEM_IN_USER=
        "select problem1,problem2 from User where id=?;";

static const QString SEARCH_FRIEND_IN_USER=
        "select User.id, User.nickname, User.isonline from User,Friend where "
        " (Friend.lefthand=? and Friend.righthand=User.id) or "
        "(Friend.righthand=? and Friend.lefthand=User.id ); ";

static const QString SEARCH_GROUP_BY_ID=
        "select Flock.flockID,Flock.flockName from Flock,FlockMember "
        " where FlockMember.userID=? and FlockMember.flockID = Flock.flockID ;";

static const QString SEARCH_NOTI_BY_ID=
        "select RequestFriend.requestID,User.nickname,RequestFriend.message,RequestFriend.time from RequestFriend,User"
        " where RequestFriend.pass=0 and RequestFriend.replyID=? and User.id=RequestFriend.requestID;";

static const QString SEARCH_ID_IN_USER=
        "select 100000+count(*) from User;";

static const QString CHECK_ANSWER_IN_USER=
        "select * from User where id=? and answer1=? and answer2=? ;";

static const QString CHECK_FRIEND_REQUEST=
        "select * from Friend where (lefthand=? and righthand=?) or (righthand=? and lefthand=?)";

static const QString CHECK_REQUEST_IN_FRIEND_REQUEST=
        "select * from RequestFriend where requestID=? and replyID=?";

static const QString GENERATE_TALK_ID=
        "select count(*) from Talk;";

static const QString GENERATE_FILE_ID=
        "select count(*) from File;";

static const QString SEARCH_TALK_HISTORY=
        "select * from Talk where (sendID=? and receiveID=?) or (receiveID=? and sendID=?) order by talkID desc limit 5; ";

static const QString SEARCH_HISTORY_DOCUMENT=
        "select * from Talk where (sendID=? and receiveID=?) or (receiveID=? and sendID=?) order by talkID";

static const QString GET_ALL_FLOCK_MEMBER=
        "select id,isonline from User,FlockMember where FlockMember.flockID=? and FlockMember.userID=User.id;";

static const QString GET_FLOCK_TALK_ID=
        "select count(*) from FlockTalk;";

static const QString FIND_FLOCK_USER=
        "select User.id from User,FlockMember where flockID=? and userID=User.id and User.isonline=true;";

static const QString GET_FLOCK_LAST_MESSAGE=
        "select userID,message,time from FlockTalk where flockID=? order by flockTalkID desc limit 5;";

static const QString INFORM_FRIEND_OFFLINE=
        "select User.id from User,Friend where "
        " (Friend.lefthand=? and Friend.righthand=User.id) or "
        "(Friend.righthand=? and Friend.lefthand=User.id ); ";

static const QString SEARCH_NAME_BY_ID=
        "select nickname from User where id=?;";

static const QString SEARCH_PERSONAL_INFO=
        "select nickname,isonline from User where id=?;";

static const QString GET_BBS_RECORD_IN_BBS=
        "select bbsID,User.nickname,title,content,time,userID from BBS,User where BBS.userID=User.id;";

static const QString GET_BBS_ID=
        "select max(bbsID)+1 from BBS;";

static const QString GET_BBS_REPLY=
        "select User.nickname,content,time from User,REPLY where User.id=REPLY.userID and bbsID=?;";

static const QString GET_REPLY_ID=
        "select count(*) from REPLY;";

Database::Database(QObject *parent) :
    QObject(parent)
{
    m_database=new QSqlDatabase;
}

Database::~Database()
{
    if(m_database!=nullptr)
    {
        if(m_database->isOpen())
            m_database->close();
        delete m_database;
        m_database=nullptr;
    }
}

//建立连接
bool Database::createconnection()
{
    if(m_database==nullptr)
        m_database=new QSqlDatabase;
    if(m_database->isOpen())
       return true;
    if(QSqlDatabase::contains("server"))
    {
        *m_database=QSqlDatabase::database("server");
        qDebug()<<"serverDB has existed";
    }
    else {
        *m_database=QSqlDatabase::addDatabase("QMYSQL","server");
        m_database->setDatabaseName("server");
     //   qDebug()<<"new DB has established";
    }
    m_database->setUserName("test");
    m_database->setPassword("");
    m_database->setHostName(QLatin1String("localhost"));
    bool ret=m_database->open();
    if(ret)
    {
        return true;
    }
    else {
        qDebug()<<"open database error "<<m_database->lastError();
        return false;
    }
}

bool Database::initdatabase()
{
    if(!createconnection())
        return false;
    //创建数据表，仅仅创建一次！
    //createTable();
    QSqlQuery query(*m_database);
    query.exec(UPDATE_STATUS_IN_USERINFORMATION_SQL);  //数据库刚初始化时，默认所有用户在下线状态
    errorSQLOrder(query,"initDatabase");
    if(!query.isActive())
    {
        m_database->close();
        return false;
    }
    else {
        qDebug()<<"database update status successful!";
        m_database->close();
        return true;
    }
}

//sql 语句报错
void Database::errorSQLOrder(QSqlQuery query, QString mark)
{
    //如果SQL语句错误，就弹出警告信息
    if(!query.isActive())
    {
        QString str = query.lastError().text() + "\n" + mark;
        QMessageBox::warning(nullptr, "ERROR", str);
    }
}

//创建数据表，仅在创建数据库的时候创建一次
void Database::createTable()
{
    if(!createconnection())
       return ;
    QSqlQuery query(*m_database);
    query.exec(CREATE_TABLE_USERINFO);
    query.exec(CREATE_TABLE_FRIEND);
    query.exec(CREATE_TABLE_REQUEST_FRIEND);
    query.exec(CREATE_TABLE_FLOCK);
    query.exec(CREATE_TABLE_FLOCK_MEMBER);
    query.exec(CREATE_TABLE_TALKINFO);
    query.exec(CREATE_TABLE_FLOCKTALKINFO);
    query.exec(CREATE_TABLE_BBSINFO);
    query.exec(CREATE_TABLE_BBSREPLY);
    errorSQLOrder(query,"create table");
    if(!query.isActive())
    {
        m_database->close();
        return ;
    }
    qDebug()<<"Table has been established";
    m_database->close();
}


int Database::searchUserInUserInformation(const LoginInfo &loginfo, MainWindowInfo &maininfo)
{
    if(!createconnection())
       return false;
    //qDebug()<<"login ";
    QSqlQuery query(*m_database);
    query.prepare(SEARCH_USER_IN_USERINFORMATION_SQL);
    query.addBindValue(loginfo.m_userID);
    query.addBindValue(loginfo.m_password);
    query.exec();
    //qDebug()<<"login :"<<loginfo.m_userID<<loginfo.m_password;
    errorSQLOrder(query, "login-search");
    if (!query.isActive())
    {
        m_database->close();
        return LOGIN_FAIL;
    }
    if (query.size() <= 0)
    {
        m_database->close();
        return LOGIN_FAIL;
    }
    if(query.next())
    {
        maininfo.myID=query.value(0).toString();
        maininfo.myname=query.value(6).toString();
        //qDebug()<<"myID"<<maininfo.myID<<maininfo.myname;
        QSqlQuery query1(*m_database);
        query1.prepare(SEARCH_FRIEND_IN_USER);
        query1.addBindValue(loginfo.m_userID);
        query1.addBindValue(loginfo.m_userID);
        query1.exec();
        errorSQLOrder(query1,"search all friend");
        if(!query1.isActive())
        {
            m_database->close();
            return LOGIN_FAIL;
        }
        else {
            while(query1.next())
            {
                FriendInfo Friend;
                Friend.ID=query1.value(0).toString();
                Friend.name=query1.value(1).toString();
                Friend.isonline=query1.value(2).toBool();
                maininfo.friends.push_back(Friend);

            }
        }

        QSqlQuery query2(*m_database);
        query2.prepare(SEARCH_GROUP_BY_ID);
        query2.addBindValue(loginfo.m_userID);
        query2.exec();
        errorSQLOrder(query2,"search all group");
        if(!query2.isActive())
        {
            m_database->close();
            return LOGIN_FAIL;
        }
        else {
            while(query2.next())
            {
                GroupInfo group;
                group.ID=query2.value(0).toString();
                group.name=query2.value(1).toString();
                maininfo.groups.push_back(group);
            }

        }
        //qDebug()<<"group "<<maininfo.groups.size();
        QSqlQuery query3(*m_database);
        query3.prepare(SEARCH_NOTI_BY_ID);
        query3.addBindValue(loginfo.m_userID);
        query3.exec();
        if(!query3.isActive())
        {
            m_database->close();
            return LOGIN_FAIL;
        }
        else {
            while(query3.next())
            {
                NotiInfo noti;
                noti.ID=query3.value(0).toString();
                noti.name=query3.value(1).toString();
                noti.message=query3.value(2).toString();
                noti.time=query3.value(3).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
                maininfo.notifications.push_back(noti);
            }

        }
        //qDebug()<<"notification :"<<maininfo.notifications.size();
        qDebug()<<tr("User %1 login").arg(loginfo.m_userID);
        if(updateStatus(true,loginfo.m_userID))
        {
            m_database->close();
            return LOGIN_SUCCESS;
        }
    }
    m_database->close();
    return LOGIN_FAIL;
}

bool Database::updateStatus(bool status, const int &id)
{
    if(!createconnection())
       return false;
    QSqlQuery query(*m_database);
    query.prepare(UPDATE_STATUS_IN_USERINFORMATION_BY_ID_SQL);
    query.addBindValue(status);
    query.addBindValue(id);
    query.exec();
    errorSQLOrder(query,"update status");
    if (!query.isActive())
    {
        qDebug()<<"QUERY_FAIL::"<< query.lastError().text();
        m_database->close();
        return false;
    }
    m_database->close();
    return true;
}

//搜索密保问题
int Database::searchProblemInUser(const LoginInfo &tmp,Userinfo &user)
{
    if(!createconnection())
       return false;

    QSqlQuery query(*m_database);
    query.prepare(SEARCH_PROBLEM_IN_USER);
    query.addBindValue(tmp.m_userID);
    query.exec();
    errorSQLOrder(query,"search problem");
    if(!query.isActive())
    {
        qDebug()<<"Query fail :"<<query.lastError().text();
        m_database->close();
        return FORGET_PASSWORD_PROBLEM_FAIL;
    }
    else {
        if(query.next())
        {
            user.problem1=query.value(0).toString();
            user.problem2=query.value(1).toString();
        }

        if(user.problem1=="" || user.problem2=="")
        {
            m_database->close();
            return FORGET_PASSWORD_PROBLEM_FAIL;
        }
        m_database->close();
        return FORGET_PASSWORD_PROBLEM_SUCCESS;
    }
}
//注册并且分配id号
int Database::giveidnumber( Userinfo &tmp,Userinfo &info)
{
    if(!createconnection())
       return false;

    info.nickname=tmp.nickname;
    info.password=tmp.password;
    info.problem1=tmp.problem1;
    info.answer1=tmp.answer1;
    info.problem2=tmp.problem2;
    info.answer2=tmp.answer2;

    QSqlQuery query(*m_database);
    query.exec(SEARCH_ID_IN_USER);
    errorSQLOrder(query,"get id");
    if(!query.isActive())
    {
        m_database->close();
        return REGISTER_FAIL;
    }
    else {
        if(query.next())
        {
            info.id=query.value(0).toInt();
        }
        QSqlQuery query1(*m_database);
        query1.prepare(INSERT_INTO_USER);
        query1.addBindValue(info.id);
        query1.addBindValue(info.password);
        query1.addBindValue(info.problem1);
        query1.addBindValue(info.answer1);
        query1.addBindValue(info.problem2);
        query1.addBindValue(info.answer2);
        query1.addBindValue(info.nickname);
        query1.addBindValue("");
        query1.addBindValue(QDateTime::currentDateTime());
        query1.addBindValue(false);
        query1.exec();
        errorSQLOrder(query1,"insert into User");
        if(!query1.isActive())
        {
            m_database->close();
            return REGISTER_FAIL;
        }
        m_database->close();
        return REGISTER_SUCCESS;
    }
}
//检查密保问题答案是否正确
int Database::checkanswer( Userinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(CHECK_ANSWER_IN_USER);
    query.addBindValue(tmp.id);
    query.addBindValue(tmp.answer1);
    query.addBindValue(tmp.answer2);
    query.exec();
    errorSQLOrder(query,"check answer");

    if(!query.isActive())
    {
        m_database->close();
        return CHECK_FAIL;
    }
    else
    {
        m_database->close();
        if(query.next())
        {
            return CHECK_SUCCESS;
        }
        else
        {
            return CHECK_FAIL;
        }
    }
}


//修改password
int Database::changepassword(const LoginInfo &tmp)
{
    if(!createconnection())
       return false;
    //qDebug()<<"change password start";
    QSqlQuery query(*m_database);
    query.prepare(CHANGE_PASSWORD_IN_USER);
    query.addBindValue(tmp.m_password);
    query.addBindValue(tmp.m_userID);
    query.exec();
    errorSQLOrder(query,"change password");
    if(!query.isActive())
    {
        m_database->close();
        qDebug()<<"change pwd fail";
        return CHANGE_PWD_FAIL;
    }
    else
    {
        m_database->close();
        qDebug()<<"change pwd success! ";
        return CHANGE_PWD_SUCCESS;
    }
}

//将申请好友的消息存入数据库
int Database::requestfriend( UserTalkinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query0(*m_database);
    query0.prepare(CHECK_FRIEND_REQUEST);
    query0.addBindValue(tmp.send_id);
    query0.addBindValue(tmp.receive_id);
    query0.addBindValue(tmp.receive_id);
    query0.addBindValue(tmp.send_id);
    query0.exec();
    errorSQLOrder(query0,"friend already exist");
    if(!query0.isActive())
    {
        m_database->close();
        return SEND_REQUEST_FAIL;
    }
    else
    {
        //qDebug()<<"friend request : "<<query0.size();
        if(query0.size()!=0)
        {
            m_database->close();
            return FRIEND_EXIST;
        }
    }
    QSqlQuery query2(*m_database);
    query2.prepare(CHECK_REQUEST_IN_FRIEND_REQUEST);
    query2.addBindValue(tmp.send_id);
    query2.addBindValue(tmp.receive_id);
    query2.exec();
    errorSQLOrder(query2,"repeat request");
    if(!query2.isActive())
    {
        m_database->close();
        return SEND_REQUEST_FAIL;
    }
    else
    {
        if(query2.size()>0)
        {
            m_database->close();
            return FRIEND_EXIST;
        }
    }
    QSqlQuery query(*m_database);
    tmp.send_time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    query.prepare(INSERT_REQUEST_FRIEND_IN_DB);
    query.addBindValue(tmp.send_id);
    query.addBindValue(tmp.receive_id);
    query.addBindValue(tmp.message);
    query.addBindValue(QDateTime::currentDateTime());
    query.addBindValue(0);
    query.exec();
    errorSQLOrder(query,"request friend");
    if(!query.isActive())
    {
        m_database->close();
        return SEND_REQUEST_FAIL;
    }
    else
    {
        qDebug()<<"send request success!";
        m_database->close();
        return SEND_REQUEST_SUCCESS;
    }
}

int Database::search_name_by_id(Userinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(SEARCH_NAME_BY_ID);
    query.addBindValue(tmp.id);
    query.exec();
    errorSQLOrder(query,"search name");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else {
        if(query.next())
        {
            tmp.nickname=query.value(0).toString();
        }
        m_database->close();
        return 1;
    }
}

//同意好友申请
int Database::agreefriendrequest( UserTalkinfo &tmp,Userinfo &p)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(AGREE_FRIEND_REQUEST);
    query.addBindValue(tmp.send_id);
    query.addBindValue(tmp.receive_id);
    query.exec();
    errorSQLOrder(query,"agree friend");

    if(!query.isActive())
    {
        m_database->close();
        return SEND_REQUEST_FAIL;
    }
    else {
        QSqlQuery query1(*m_database);
        query1.prepare(ADD_FRIEND_IN_FRIEND);
        query1.addBindValue(tmp.send_id);
        query1.addBindValue(tmp.receive_id);
        query1.exec();
        errorSQLOrder(query1,"insert friend");
        if(!query1.isActive())
        {
            m_database->close();
            return SEND_REQUEST_FAIL;
        }
        else
        {
            QSqlQuery query2(*m_database);
            query2.prepare(UPDATE_NEW_FRIEND);
            query2.addBindValue(tmp.send_id);
            query2.exec();
            errorSQLOrder(query2,"send friend");
            if(!query2.isActive())
            {
                m_database->close();
                return SEND_REQUEST_FAIL;
            }
            if(query2.next())
            {
                p.id=query2.value(0).toInt();
                p.nickname=query2.value(1).toString();
                p.status=query2.value(2).toInt();
            }
            m_database->close();
            return SEND_REQUEST_SUCCESS;
        }
    }
}

//拒绝好友申请
int Database::refusefriendrequest( UserTalkinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(REFUSE_FRIEND_REQUEST);
    query.addBindValue(tmp.send_id);
    query.addBindValue(tmp.receive_id);
    query.exec();
    errorSQLOrder(query,"refuse friend");
    if(!query.isActive())
    {
        m_database->close();
        return SEND_REQUEST_FAIL;
    }
    else {
        m_database->close();
        return SEND_REQUEST_SUCCESS;
    }
}

int Database::update_friend_list(Userinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(SEARCH_PERSONAL_INFO);
    query.addBindValue(tmp.id);
    query.exec();
    errorSQLOrder(query,"find name,online");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else {
        if(query.next())
        {
            tmp.nickname=query.value(0).toString();
            tmp.status=query.value(1).toInt();
        }
        m_database->close();
        return 1;
    }
}

int Database::talktofriend( UserTalkinfo &tmp)
{
    if(!createconnection())
        return false;
    int id;
    QSqlQuery query0(*m_database);
    query0.prepare(GENERATE_TALK_ID);
    query0.exec();
    errorSQLOrder(query0,"generate talkID");
    if(!query0.isActive())
    {
        m_database->close();
        return -1;
    }
    else
    {
        if(query0.next())
        {
            id=query0.value(0).toInt();
        }
        else {
            id=0;
        }
    }
    QSqlQuery query(*m_database);
    query.prepare(ADD_MESSAGE_TO_TALK);
    query.addBindValue(id);
    query.addBindValue(tmp.send_id);
    query.addBindValue(tmp.receive_id);
    query.addBindValue(tmp.message);
    query.addBindValue(QDateTime::currentDateTime());
    query.exec();
    errorSQLOrder(query,"save talk message");
    m_database->close();
    return -1; //-1表示不返回任何有意义消息

}

int Database::search_talk_message( UserTalkinfo &talk, QVector<UserTalkinfo> &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(SEARCH_TALK_HISTORY);
    query.addBindValue(talk.send_id);
    query.addBindValue(talk.receive_id);
    query.addBindValue(talk.send_id);
    query.addBindValue(talk.receive_id);

    query.exec();
    errorSQLOrder(query,"search history ");
    if(!query.isActive())
    {
        m_database->close();
        return NO_MESSAGE;
    }
    else {
        while(query.next())
        {
            UserTalkinfo temp;
            temp.talk_id=query.value(0).toInt();
            temp.send_id=query.value(1).toInt();
            temp.receive_id=query.value(2).toInt();
            temp.message=query.value(3).toString();
            temp.send_time=query.value(4).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
            tmp.push_back(temp);
        }
        qDebug()<<"talk  size"<<tmp.size();
        if(tmp.size()==0)
        {
            m_database->close();
            return NO_MESSAGE;
        }
        else {
           m_database->close();
           return HAVE_MESSAGE;
        }
    }
}

int Database::search_history_document(UserTalkinfo &m, QVector<UserTalkinfo> &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(SEARCH_HISTORY_DOCUMENT);
    query.addBindValue(m.send_id);
    query.addBindValue(m.receive_id);
    query.addBindValue(m.send_id);
    query.addBindValue(m.receive_id);
    query.exec();
    errorSQLOrder(query,"search history document");

    if(!query.isActive())
    {
        m_database->close();
        return NO_MESSAGE_RECORD;
    }
    else
    {
        while(query.next())
        {
            UserTalkinfo temp;
            temp.talk_id=query.value(0).toInt();
            temp.send_id=query.value(1).toInt();
            temp.receive_id=query.value(2).toInt();
            temp.message=query.value(3).toString();
            temp.send_time=query.value(4).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
            tmp.push_back(temp);
        }
        m_database->close();
        return HAVE_MESSAGE_RECODRD;
    }
}


int Database::create_new_flock(Flockinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(CREATE_NEW_FLOCK_ID);
    query.exec();
    errorSQLOrder(query,"get flock id");
    if(!query.isActive())
    {
        m_database->close();
        return CREATE_FLOCK_FAIL;
    }
    else {
        int flockid;
        if(query.next())
        {
            flockid=query.value(0).toInt();
        }
        else {
            flockid=0;
        }
        tmp.flock_id=flockid;
        tmp.create_time=QDateTime::currentDateTime();
        tmp.user_num=1;
        QSqlQuery query1(*m_database);
        query1.prepare(CREATE_NEW_FLOCK);
        query1.addBindValue(flockid);
        query1.addBindValue(tmp.creator_id);
        query1.addBindValue(tmp.flock_name);
        query1.addBindValue(1);
        query1.addBindValue(QDateTime::currentDateTime());
        query1.exec();
        errorSQLOrder(query1,"create new flock");
        if(!query1.isActive())
        {
            m_database->close();
            return CREATE_FLOCK_FAIL;
        }
        else {
            QSqlQuery query2(*m_database);
            query2.prepare(CREATE_NEW_FLOCK_MEMBER);
            query2.addBindValue(tmp.flock_id);
            query2.addBindValue(tmp.creator_id);
            query2.exec();
            errorSQLOrder(query2,"add flock member");
            if(!query2.isActive())
            {
                m_database->close();
                return CREATE_FLOCK_FAIL;
            }

            m_database->close();
            return CREATE_FLOCK_SUCCESS;
        }
    }
}


int Database::get_all_flock_member(Flockinfo &f, QVector<FlockMember> &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GET_ALL_FLOCK_MEMBER);
    query.addBindValue(f.flock_id);
    query.exec();
    errorSQLOrder(query,"get flock member");
    if(!query.isActive())
    {
        m_database->close();
        return GET_FLOCK_MEMBERS_FAIL;
    }
    else {
        while(query.next())
        {
            FlockMember temp;
            temp.user_id=query.value(0).toInt();
            temp.loginStatus=query.value(1).toInt();
            tmp.push_back(temp);
        }
        m_database->close();
        return GET_FLOCK_MEMBERS_SUCCESS;
    }
}

int Database::flock_add_member(FlockMember &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(FLOCK_ADD_MEMBER_REQUEST);
    query.addBindValue(tmp.flock_id);
    query.addBindValue(tmp.user_id);
    query.exec();
    errorSQLOrder(query,"flock add member ");
    if(!query.isActive())
    {
        m_database->close();
        return ADD_FLOCK_FAIL;
    }
    else {
        m_database->close();
        return ADD_FLOCK_SUCCESS;
    }
}

int Database::change_flock_name(Flockinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(CHANGE_FLOCK_NAME_IN_FLOCK);
    query.addBindValue(tmp.flock_name);
    query.addBindValue(tmp.flock_id);
    query.exec();
    errorSQLOrder(query,"update flock name");
    if(!query.isActive())
    {
        m_database->close();
        return CHANGE_FLOCK_NAME_FAIL;
    }
    else
    {
        m_database->close();
        return CHANGE_FLOCK_NAME_SUCCESS;
    }
}

int Database::change_user_name(Userinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(CHAGNE_USER_NAME);
    query.addBindValue(tmp.nickname);
    query.addBindValue(tmp.id);
    query.exec();
    errorSQLOrder(query,"change user name");
    if(!query.isActive())
    {
        m_database->close();
        return CHANGE_INFORMATION_FAIL;
    }
    else
    {
        m_database->close();
        return CHANGE_INFORMATION_SUCCESS;
    }
}

int Database::send_flock_message(FlockTalkinfo &tmp,QVector<FlockMember> &fr)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GET_FLOCK_TALK_ID);
    query.exec();
    errorSQLOrder(query,"get flock talk id");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else {
        if(query.next())
        {
            tmp.flocktalk_id=query.value(0).toInt();
        }
        tmp.send_time=QDateTime::currentDateTime();

        QSqlQuery query1(*m_database);
        query1.prepare(SEND_FLOCK_MESSAGE);
        query1.addBindValue(tmp.flocktalk_id);
        query1.addBindValue(tmp.flock_id);
        query1.addBindValue(tmp.send_id);
        query1.addBindValue(tmp.message);
        query1.addBindValue(tmp.send_time);
        query1.exec();
        errorSQLOrder(query1,"insert flock talk");
        if(!query1.isActive())
        {
            m_database->close();
            return -1;
        }
        QSqlQuery query2(*m_database);
        query2.prepare(FIND_FLOCK_USER);
        query2.addBindValue(tmp.flock_id);
        query2.exec();
        while(query2.next())
        {
            FlockMember temp;
            temp.user_id=query2.value(0).toInt();
            temp.loginStatus=1;
            fr.push_back(temp);
        }

        m_database->close();
        return 1;
    }
}

int Database::send_last_message_in_flock(Flockinfo &fl, QVector<FlockTalkinfo> &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GET_FLOCK_LAST_MESSAGE);
    query.addBindValue(fl.flock_id);
    query.exec();
    errorSQLOrder(query,"get latest flock message");
    if(!query.isActive())
    {
        m_database->close();
        return NO_FLOCK_MESSAGE;
    }
    else
    {
        while(query.next())
        {
            FlockTalkinfo temp;
            temp.send_id=query.value(0).toInt();
            temp.message=query.value(1).toString();
            temp.send_time=query.value(2).toDateTime();
            tmp.push_back(temp);
        }
        m_database->close();
        return HAVE_FLOCK_MESSAGE;
    }
}


int Database::save_file_in_db(UserTalkinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GENERATE_FILE_ID);
    query.exec();
    errorSQLOrder(query,"produce talk ID");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else {
        if(query.next())
        {
            tmp.talk_id=query.value(0).toInt();
        }
        tmp.send_time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        QSqlQuery query1(*m_database);
        query1.prepare(SAVE_FILE_IN_DB);
        query1.addBindValue(tmp.talk_id);
        query1.addBindValue(tmp.message);
        query1.addBindValue(tmp.bit);
        query1.addBindValue(tmp.send_id);
        query1.addBindValue(tmp.receive_id);
        query1.addBindValue(QDateTime::currentDateTime());
        query1.exec();
        errorSQLOrder(query1,"save file");
        if(!query1.isActive())
        {
            m_database->close();
            return -1;
        }
        qDebug()<<"save file success";
        m_database->close();
        return 1;
    }
}

int Database::inform_offline_to_friend(int &tmp, QVector<Userinfo> &users)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(INFORM_FRIEND_OFFLINE);
    query.addBindValue(tmp);
    query.addBindValue(tmp);
    query.exec();
    errorSQLOrder(query,"inform friend offline");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else
    {
        while(query.next())
        {
            Userinfo user;
            user.id=query.value(0).toInt();
            users.push_back(user);
        }
        m_database->close();
        return 1;
    }
}

int Database::get_bbs_record(QVector<BBSinfo> &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GET_BBS_RECORD_IN_BBS);
    query.exec();
    errorSQLOrder(query,"find all bbs record");
    if(!query.isActive())
    {
        m_database->close();
        return GET_BBS_FAIL;
    }
    else
    {
        while(query.next())
        {
            BBSinfo temp;
            temp.bbs_id=query.value(0).toInt();
            temp.username=query.value(1).toString();
            temp.title=query.value(2).toString();
            temp.content=query.value(3).toString();
            temp.publish_time=query.value(4).toDateTime();
            temp.user_id=query.value(5).toInt();
            tmp.push_back(temp);
        }
        m_database->close();
        return GET_BBS_SUCCESS;
    }
}


int Database::add_new_bbs(BBSinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GET_BBS_ID);
    query.exec();
    errorSQLOrder(query,"add bbs ");
    if(!query.isActive())
    {
        return -1;
    }
    else
    {
        if(query.next())
        {
            tmp.bbs_id=query.value(0).toInt();
        }
        tmp.publish_time=QDateTime::currentDateTime();

        QSqlQuery query1(*m_database);
        query1.prepare(ADD_NEW_RECORD_IN_BBS);
        query1.addBindValue(tmp.bbs_id);
        query1.addBindValue(tmp.user_id);
        query1.addBindValue(tmp.title);
        query1.addBindValue(tmp.content);
        query1.addBindValue(tmp.publish_time);
        query1.exec();
        errorSQLOrder(query1,"insert record in bbs");
        if(!query1.isActive())
        {
            m_database->close();
            return -1;
        }
        else
        {
            QSqlQuery query2(*m_database);
            query2.prepare(SEARCH_NAME_BY_ID);
            query2.addBindValue(tmp.user_id);
            query2.exec();
            if(!query2.isActive())
            {
                m_database->close();
                return -1;
            }
            if(query2.next())
            {
                tmp.username=query2.value(0).toString();
            }

            m_database->close();
            return 1;
        }
    }
}

int Database::get_all_reply_on_bbs(BBSinfo &inf, QVector<BBSreply> &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GET_BBS_REPLY);
    query.addBindValue(inf.bbs_id);
    query.exec();
    errorSQLOrder(query,"get all reply");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else
    {
        while(query.next())
        {
            BBSreply temp;
            temp.username=query.value(0).toString();
            temp.text=query.value(1).toString();
            temp.reply_time=query.value(2).toDateTime();
            tmp.push_back(temp);
        }
        m_database->close();
        return 1;
    }
}


int Database::reply_to_bbs(BBSreply &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(GET_REPLY_ID);
    query.exec();
    errorSQLOrder(query,"get reply ID");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else
    {
        if(query.next())
        {
            tmp.reply_id=query.value(0).toInt();
        }
        tmp.reply_time=QDateTime::currentDateTime();
        QSqlQuery query1(*m_database);
        query1.prepare(REPLY_TO_BBS);
        query1.addBindValue(tmp.reply_id);
        query1.addBindValue(tmp.user_id);
        query1.addBindValue(tmp.bbs_id);
        query1.addBindValue(tmp.text);
        query1.addBindValue(tmp.reply_time);
        query1.exec();
        errorSQLOrder(query1,"insert into reply");
        m_database->close();
        return 1;
    }
}

int Database::delete_bbs(BBSinfo &tmp)
{
    if(!createconnection())
        return false;
    QSqlQuery query(*m_database);
    query.prepare(DELETE_BBS_IN_BBS);
    query.addBindValue(tmp.bbs_id);
    query.exec();
    errorSQLOrder(query,"delete bbs in bbs");
    if(!query.isActive())
    {
        m_database->close();
        return -1;
    }
    else
    {
        QSqlQuery query1(*m_database);
        query1.prepare( DELETE_BBS_IN_REPLY);
        query1.addBindValue(tmp.bbs_id);
        query1.exec();
        errorSQLOrder(query1,"delete bbs in reply");
        m_database->close();
        return 1;
    }
}
