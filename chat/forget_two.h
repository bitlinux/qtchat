#ifndef FORGET_TWO_H
#define FORGET_TWO_H

#include <QWidget>
#include <QDesktopWidget>
#include <QMessageBox>
class tcpsocket;
namespace Ui {
class forget_two;
}

class forget_two : public QWidget
{
    Q_OBJECT

public:
    explicit forget_two(QWidget *parent = nullptr);
    ~forget_two();
    void set_ID(QString id);

private slots:
    void on_reset_clicked();
    void readmessage(int &);
    void send_request();

private:
    Ui::forget_two *ui;
    tcpsocket *m_tcpsocket;
    QString m_id;
};

#endif // FORGET_TWO_H
