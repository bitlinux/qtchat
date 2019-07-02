#ifndef REG_TWO_H
#define REG_TWO_H

#include <QWidget>
#include <QMessageBox>
#include <QDesktopWidget>
#include<QDataStream>
#include "reg_success.h"
class tcpsocket;

namespace Ui {
class reg_two;
}

class reg_two : public QWidget
{
    Q_OBJECT

public:
    explicit reg_two(QWidget *parent = nullptr);
    ~reg_two();
    void linksignal();
    QString nickname;
    QString password;


signals:
    void Back();

private slots:
    void on_back_clicked();

    void on_register_2_clicked();

    void read_the_message(int &);

    void send_request();


private:
    Ui::reg_two *ui;
    tcpsocket *m_tcpsocket;
    QDataStream in;

};

#endif // REG_TWO_H
