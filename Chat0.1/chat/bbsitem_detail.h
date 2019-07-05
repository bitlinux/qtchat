#ifndef BBSITEM_DETAIL_H
#define BBSITEM_DETAIL_H

#include <QDialog>
#include "tcpsocket.h"

namespace Ui {
class bbsitem_detail;
}

class bbsitem_detail : public QDialog
{
    Q_OBJECT

public:
    explicit bbsitem_detail(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString ibbs_id = "", QString poster_id = "", QString my_id = "", QString icontent = "", QString ititle = "", QString iposter_name = "", QString post_time= "" );
    ~bbsitem_detail();
    QString getContent();
    struct reply_history{
        QString name,time,content;
    };
    QVector <reply_history> historys;

private slots:
    void on_buttonBox_accepted();

    void on_Delete_clicked();
    void get_reply_history();

private:
    Ui::bbsitem_detail *ui;
    tcpsocket *m_tcpsocket;
    QString  bbs_id, posterID, myID, content, title, poster_name, postTime;
};

#endif // BBSITEM_DETAIL_H
