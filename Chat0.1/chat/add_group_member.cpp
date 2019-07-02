#include "add_group_member.h"
#include "ui_add_group_member.h"

add_group_member::add_group_member(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_group_member)
{
    ui->setupUi(this);
}

add_group_member::~add_group_member()
{
    delete ui;
}

void add_group_member::on_pushButton_clicked()
{
    //send groupID,new_memberID to server
    this->close();
}
