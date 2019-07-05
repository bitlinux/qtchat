#ifndef BBS_H
#define BBS_H

#include <QWidget>
#include <QCloseEvent>
#include "tcpsocket.h"
#include "bbsitem.h"

namespace Ui {
class bbs;
}

class bbs : public QWidget
{
    Q_OBJECT

public:
    explicit bbs(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString myID = "000000", QString myname = "name");
    ~bbs();
    void adbbsitem(QString title = "title", QString content = "content", QString name = "name", QString bbs_id="", QString poster_id = "", QString my_id="", QString post_time = "");

private slots:
    void on_shared_button_clicked();

    void on_postButton_clicked();

    void on_upload_button_clicked();

    void on_quitButton_clicked();

    void get_item();

    void get_single_item();

    void closeEvent(QCloseEvent *event);

private:
    Ui::bbs *ui;
    tcpsocket *m_tcpsocket;
    QString myid,myname;
    struct bbsItem {
        QString title;
        int id;
        int poster_id;
        QString content;
        QString name;
        QString posttime;
    };
    QVector<bbsItem> bbsItems;

};

#endif // BBS_H
