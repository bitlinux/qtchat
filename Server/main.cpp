#include<QApplication>
#include <QtCore/QTextCodec>
#include"server_message.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    ServerMessage w;
    w.runServer();
    return a.exec();
}
