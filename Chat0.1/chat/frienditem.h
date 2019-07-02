#ifndef FRIENDITEM_H
#define FRIENDITEM_H

#include <QWidget>
#include <QMessageBox>
#include "private_chat.h"
#include "tcpsocket.h"

namespace Ui {
class frienditem;
}

class frienditem : public QWidget
{
    Q_OBJECT

public:
    explicit frienditem(QWidget *parent = nullptr,tcpsocket *m = nullptr, QString header_path = "../chat/resources/yl.png", QString otherid = "000000", QString othername = "Linux", QString myid="", QString myname="", bool isonline=false);
    ~frienditem();
    QString otherID, othername;
    QString myID, myname;
    QString header_path;

private slots:
    void on_header_button_clicked();

private:
    Ui::frienditem *ui;
    tcpsocket *m_tcpsocket;
    private_chat *pchat;
};

#endif // FRIENDITEM_H
