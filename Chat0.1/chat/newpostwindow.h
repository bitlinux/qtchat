#ifndef NEWPOSTWINDOW_H
#define NEWPOSTWINDOW_H

#include <QDialog>
#include "tcpsocket.h"
namespace Ui {
class NewPostWindow;
}

class NewPostWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewPostWindow(QWidget *parent = nullptr, tcpsocket *m = nullptr, QString id = "");
    ~NewPostWindow();
    QString getTitle();
    QString getContent();
    bool isContentEmpty();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewPostWindow *ui;
    QString id;
    tcpsocket *m_tcpsocket;
};

#endif // NEWPOSTWINDOW_H
