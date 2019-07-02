#include "reg_success.h"
#include "ui_reg_success.h"

reg_success::reg_success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg_success)
{
    ui->setupUi(this);
}

reg_success::~reg_success()
{
    delete ui;
}

void reg_success::on_ok_clicked()
{
    this->close();
}

/*show the ID number*/
void reg_success::set_ID(QString id)
{
    ui->ID->setText(id);
}
