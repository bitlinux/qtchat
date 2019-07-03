#ifndef GROUPITEM_H
#define GROUPITEM_H

#include <QWidget>
#include "group_chat.h"
#include "tcpsocket.h"
#include "constant.h"

namespace Ui {
class groupitem;
}

class groupitem : public QWidget
{
    Q_OBJECT

public:
    explicit groupitem(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString myid = "", QString gID = "", QString gname = "", QVector<FlockMember> fm = {}, QString gphoto="../resources/yl.png");
    ~groupitem();

    QString header_path;
    QString id, name;
private slots:
    void on_header_button_clicked();

private:
    Ui::groupitem *ui;
    tcpsocket *m_tcpsocket;
    QString myID;
    QString groupID;
    QString groupname;
    QVector<FlockMember> fm;
    group_chat *gchat;

};

#endif // GROUPITEM_H
