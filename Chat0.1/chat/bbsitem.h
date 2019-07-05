#ifndef BBSITEM_H
#define BBSITEM_H

#include <QWidget>
#include "tcpsocket.h"
#include "bbsitem_detail.h"
#include "constant.h"

namespace Ui {
class bbsitem;
}

class bbsitem : public QWidget
{
    Q_OBJECT

public:
    explicit bbsitem(QWidget *parent = nullptr,tcpsocket *m = nullptr, QString bbs_id = "", QString poster_id = "", QString my_id = "", QString title = "title", QString content = "content",QString other_name = "name", QString post_time = "");
    ~bbsitem();
    QString title, content, otherName, posterID, myID, postTime;


private slots:
    void on_post_title_clicked();

private:
    Ui::bbsitem *ui;
    QString bbs_id;
    tcpsocket *m_tcpsocket;
};

#endif // BBSITEM_H
