#ifndef PRIVATE_CHAT_MESSAGE_H
#define PRIVATE_CHAT_MESSAGE_H

#include <QDialog>
#include "constant.h"

namespace Ui {
class private_chat_message;
}

class private_chat_message : public QDialog
{
    Q_OBJECT

public:
    explicit private_chat_message(QWidget *parent = nullptr);
    ~private_chat_message();
    void set_information(QVector<UserTalkinfo> tinfo);

private slots:
    void on_close_clicked();

private:
    Ui::private_chat_message *ui;
};

#endif // PRIVATE_CHAT_MESSAGE_H
