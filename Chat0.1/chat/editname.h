#ifndef EDITNAME_H
#define EDITNAME_H

#include <QDialog>
class tcpsocket;

namespace Ui {
class editName;
}

class editName : public QDialog
{
    Q_OBJECT

public:
    explicit editName(QWidget *parent = nullptr);
    ~editName();

private slots:
    void readmessage();

    void on_pushButton_clicked();

private:
    Ui::editName *ui;
    tcpsocket *m_tcpsocket;
    QString m_id;
};

#endif // EDITNAME_H
