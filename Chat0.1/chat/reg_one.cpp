#include "reg_one.h"
#include "ui_reg_one.h"

reg_one::reg_one(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reg_one)
{
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);
    ui->setupUi(this);
}

reg_one::~reg_one()
{
    delete ui;
}

/*go to the next register*/
void reg_one::on_next_clicked()
{
    if(this->ui->nickname->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Nickname cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->password->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Password cannot be empty!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->again->text().length() == 0)
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("Please enter the password again!");
        QMessageBox::about(this, title, information);
        return ;
    }
    if(this->ui->again->text() != this->ui->password->text())
    {
        QString title = title.fromLocal8Bit("Warning");
        QString information = information.fromLocal8Bit("The password entered twice must be the same!");
        QMessageBox::about(this, title, information);
        return ;
    }
    reg.nickname = this->ui->nickname->text();
    reg.password = this->ui->password->text();
    reg.show();
    this->hide();
    connect(&reg, SIGNAL(Back()), this, SLOT(show()));

}
