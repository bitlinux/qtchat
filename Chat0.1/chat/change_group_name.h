#ifndef CHANGE_GROUP_NAME_H
#define CHANGE_GROUP_NAME_H

#include <QDialog>

namespace Ui {
class change_group_name;
}

class change_group_name : public QDialog
{
    Q_OBJECT

public:
    explicit change_group_name(QWidget *parent = nullptr);
    ~change_group_name();

private slots:


    void on_cancel_clicked();

    QString on_change_clicked();

private:
    Ui::change_group_name *ui;
};

#endif // CHANGE_GROUP_NAME_H
