#ifndef REG_SUCCESS_H
#define REG_SUCCESS_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class reg_success;
}

class reg_success : public QDialog
{
    Q_OBJECT

public:
    explicit reg_success(QWidget *parent = nullptr);
    ~reg_success();
    void set_ID(QString id);

private slots:
    void on_ok_clicked();

private:
    Ui::reg_success *ui;
};

#endif // REG_SUCCESS_H
