#ifndef REG_ONE_H
#define REG_ONE_H

#include <QWidget>
#include <QMessageBox>
#include <QDesktopWidget>
#include "reg_two.h"

namespace Ui {
class reg_one;
}

class reg_one : public QWidget
{
    Q_OBJECT

public:
    explicit reg_one(QWidget *parent = nullptr);
    ~reg_one();

private slots:
    void on_next_clicked();

private:
    Ui::reg_one *ui;
    reg_two reg;
};

#endif // REG_ONE_H
