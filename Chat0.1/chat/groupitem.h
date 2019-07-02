#ifndef GROUPITEM_H
#define GROUPITEM_H

#include <QWidget>
#include "group_chat.h"
#include "tcpsocket.h"

namespace Ui {
class groupitem;
}

class groupitem : public QWidget
{
    Q_OBJECT

public:
    explicit groupitem(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString header_path = "/home/parallels/Desktop/yl.png", QString id = "000000", QString name = "Group0");
    ~groupitem();

    QString header_path;
    QString id, name;
private slots:
    void on_header_button_clicked();

private:
    Ui::groupitem *ui;
};

#endif // GROUPITEM_H
