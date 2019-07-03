#ifndef CREATEGROUP_H
#define CREATEGROUP_H

#include <QDialog>
#include "tcpsocket.h"

namespace Ui {
class CreateGroup;
}

class CreateGroup : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGroup(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString myid = "");
    ~CreateGroup();

private slots:
    void on_pushButton_clicked();

    void readmessage(int &type);

private:
    Ui::CreateGroup *ui;
    QString myID;
    tcpsocket *m_tcpsocket;
};

#endif // CREATEGROUP_H
