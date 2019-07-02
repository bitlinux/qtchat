#include "private_chat_message.h"
#include "ui_private_chat_message.h"

private_chat_message::private_chat_message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::private_chat_message)
{
    ui->setupUi(this);
}

private_chat_message::~private_chat_message()
{
    delete ui;
}

void private_chat_message::on_close_clicked()
{
    this->close();
}
