#ifndef GROUP_CHAT_MESSAGE_H
#define GROUP_CHAT_MESSAGE_H

#include <QDialog>

namespace Ui {
class group_chat_message;
}

class group_chat_message : public QDialog
{
    Q_OBJECT

public:
    explicit group_chat_message(QWidget *parent = nullptr);
    ~group_chat_message();

private slots:
    void on_close_clicked();

private:
    Ui::group_chat_message *ui;
};

#endif // GROUP_CHAT_MESSAGE_H
