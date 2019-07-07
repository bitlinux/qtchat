#ifndef FORGET_ONE_H
#define FORGET_ONE_H

#include <QWidget>
#include <QDesktopWidget>
#include "forget_two.h"
class tcpsocket;
namespace Ui {
class forget_one;
}

class forget_one : public QWidget
{
    Q_OBJECT

public:
    explicit forget_one(QWidget *parent = nullptr);
    ~forget_one();
    void set_information(QString id, QString pro1, QString pro2);

private slots:
    void on_next_clicked();
    void readmessage(int &);
    void send_request();

private:
    Ui::forget_one *ui;
    forget_two forget;
    tcpsocket *m_tcpsocket;
};

#endif // FORGET_ONE_H
