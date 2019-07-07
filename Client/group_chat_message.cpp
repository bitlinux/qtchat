#include "group_chat_message.h"
#include "ui_group_chat_message.h"

group_chat_message::group_chat_message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::group_chat_message)
{
    ui->setupUi(this);
}

group_chat_message::~group_chat_message()
{
    delete ui;
}

void group_chat_message::on_close_clicked()
{
    this->close();
}
