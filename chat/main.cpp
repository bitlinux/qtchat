#include "private_chat.h"
#include "group_chat.h"
#include "private_chat_message.h"
#include "group_chat_message.h"
#include "add_group_member.h"
#include "login.h"
#include "reg_one.h"
#include "reg_two.h"
#include "forget_one.h"
#include "forget_two.h"
#include "reg_success.h"
#include <QApplication>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //private_chat w;
    //group_chat v;
    //set_information from main_page!
    //QTcpSocket *tcpsocket = nullptr;
    //tcpsocket->connectToHost("127.0.0.1", 9999);
    //w.set_information("1234", "myname", "1235", "othername", "/home/new/Desktop/qq.png", tcpsocket);
    //w.show();
    //v.set_information("1234", "myname", "123566", "groupname", "/home/new/Desktop/qq.png");
    //v.show();
    login l;
    l.show();

    return a.exec();
}
