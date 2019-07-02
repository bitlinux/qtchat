#include "change_group_name.h"
#include "ui_change_group_name.h"

change_group_name::change_group_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_group_name)
{
    ui->setupUi(this);
}

change_group_name::~change_group_name()
{
    delete ui;
}

void change_group_name::on_cancel_clicked()
{
    this->close();
}

QString change_group_name::on_change_clicked()
{
    QString new_name = this->ui->lineedit->text();
    return new_name;
}
