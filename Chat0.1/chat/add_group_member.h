#ifndef ADD_GROUP_MEMBER_H
#define ADD_GROUP_MEMBER_H

#include <QDialog>

namespace Ui {
class add_group_member;
}

class add_group_member : public QDialog
{
    Q_OBJECT

public:
    explicit add_group_member(QWidget *parent = nullptr);
    ~add_group_member();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_group_member *ui;
};

#endif // ADD_GROUP_MEMBER_H
