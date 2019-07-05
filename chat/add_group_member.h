#ifndef ADD_GROUP_MEMBER_H
#define ADD_GROUP_MEMBER_H

#include <QDialog>
#include "tcpsocket.h"

namespace Ui {
class add_group_member;
}

class add_group_member : public QDialog
{
    Q_OBJECT

public:
    explicit add_group_member(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString gID = "");
    ~add_group_member();

private slots:
    void on_pushButton_clicked();

    void on_add_clicked();

private:
    Ui::add_group_member *ui;
    QString groupID;
    tcpsocket *m_tcpsocket;
};

#endif // ADD_GROUP_MEMBER_H
