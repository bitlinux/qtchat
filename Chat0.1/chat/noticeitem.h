#ifndef NOTICEITEM_H
#define NOTICEITEM_H

#include <QWidget>
#include "tcpsocket.h"

namespace Ui {
class noticeitem;
}

class noticeitem : public QWidget
{
    Q_OBJECT

public:
    explicit noticeitem(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString header_path = "/home/parallels/Desktop/yl.png",QString myid="" ,QString otherid = "000000", QString name = "NOtice",QString time = "2019/1/1", QString message="");
    ~noticeitem();

    QString header_path;
    QString myID;
    QString message;

private slots:
    void on_header_button_clicked();

private:
    Ui::noticeitem *ui;
    tcpsocket *m_tcpsocket;
};

#endif // NOTICEITEM_H
