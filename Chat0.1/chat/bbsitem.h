#ifndef BBSITEM_H
#define BBSITEM_H

#include <QWidget>
#include "tcpsocket.h"

namespace Ui {
class bbsitem;
}

class bbsitem : public QWidget
{
    Q_OBJECT

public:
    explicit bbsitem(QWidget *parent = nullptr,tcpsocket *m = nullptr, QString bbs_id = 0, QString title = "title", QString content = "content",QString name = "name");
    ~bbsitem();
    QString title, content, name;


private:
    Ui::bbsitem *ui;
    QString bbs_id;
};

#endif // BBSITEM_H
