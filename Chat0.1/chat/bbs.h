#ifndef BBS_H
#define BBS_H

#include <QWidget>
#include "tcpsocket.h"
#include "bbsitem.h"

namespace Ui {
class bbs;
}

class bbs : public QWidget
{
    Q_OBJECT

public:
    explicit bbs(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString myID = "000000", QString myname = "name", QWidget *sig = nullptr);
    ~bbs();
    void adbbsitem(QString title = "title", QString content = "content", QString name = "name", QString bbs_id="");

private slots:
    void on_shared_button_clicked();

    void on_postButton_clicked();

    void on_upload_button_clicked();

    void on_quitButton_clicked();

    void get_item();

private:
    Ui::bbs *ui;
    tcpsocket *m_tcpsocket;
    QString id,name;
    struct bbsItem {
        QString title;
        int id;
        QString content;
        QString name;
    };
    QVector<bbsItem> bbsItems;

};

#endif // BBS_H
