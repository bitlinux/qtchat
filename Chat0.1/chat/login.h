#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include <QDesktopWidget>
#include<QDataStream>
#include "reg_one.h"
#include "forget_one.h"
#include "mainwindow.h"
#include "constant.h"

class tcpsocket;

namespace Ui {
    class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_register_2_clicked();

    void on_forget_clicked();

    void on_login_2_clicked();

    void readmessage2(int &type);

    void send_login_request();

    void send_forget_request();

    void send_request();

private:
    Ui::login *ui;
    reg_one reg;
    forget_one forget;
    MainWindow *mw;
    tcpsocket *m_tcpsocket;
    MainWindowInfo maininfo;
    int m_kind;

};

#endif // LOGIN_H
