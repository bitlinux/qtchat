#include<QApplication>
#include <QtCore/QTextCodec>
#include"server_message.h"
#inlucde"fileserver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    ServerMessage w;
    fileserver v;
    w.runServer();
    return a.exec();
}
