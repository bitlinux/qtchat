#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "constant.h"
#include <QCloseEvent>
#include "addfriend.h"
#include "private_chat.h"
class tcpsocket;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, tcpsocket *m = nullptr, MainWindowInfo info={});
    ~MainWindow();
    QString myID;
    QString myname;

    void adfrienditem(QString header_path = "/home/parallels/Desktop/yl.png", QString id = "000000", QString name = "Linux", bool isonline = false);
    void adgroupitem(QString gID, QString gname, QString gphoto="../resources/yl.png");
    void adnoticeitem(QString header_path = "/home/parallels/Desktop/yl.png", QString id = "000000", QString name = "Apply Friend", QString time = "2019/1/1",QString message="");
    AddFriend *adf;
    void del_noti(int del_id);

signals:
    void send_ID(QString &);
    void receive_ID(int &);
    void send_record_ID(QString &);
    void change_name(QString &);
    void init_flock_message(QString &);
    void send_file(int &);
    void change_status(int &);
    void new_noti(int &);
    void fresh_list(int &);

private slots:
    void on_adf_but_clicked();

    void on_crgp_but_clicked();

    void on_edit_name_clicked();

    void on_edit_header_clicked();

    void readmessage(int &);

    void closeEvent(QCloseEvent *event);

    void get_new_noti(int &);

    void get_new_friend(int &);
private:
    Ui::MainWindow *ui;
    tcpsocket *m_tcpsocket;
    MainWindowInfo maininfo;


};


#endif // MAINWINDOW_H
