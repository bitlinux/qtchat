/********************************************************************************
** Form generated from reading UI file 'notice_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICE_DIALOG_H
#define UI_NOTICE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_notice_dialog
{
public:
    QPushButton *ok_button;
    QPushButton *ignore_button;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QLabel *notice_time;
    QLabel *label_3;
    QLabel *ID;
    QLabel *name;
    QLabel *time;

    void setupUi(QDialog *notice_dialog)
    {
        if (notice_dialog->objectName().isEmpty())
            notice_dialog->setObjectName(QString::fromUtf8("notice_dialog"));
        notice_dialog->resize(418, 313);
        ok_button = new QPushButton(notice_dialog);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(80, 260, 85, 28));
        ignore_button = new QPushButton(notice_dialog);
        ignore_button->setObjectName(QString::fromUtf8("ignore_button"));
        ignore_button->setGeometry(QRect(230, 260, 85, 28));
        textBrowser = new QTextBrowser(notice_dialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 140, 301, 101));
        label = new QLabel(notice_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 80, 121, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(notice_dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 121, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        notice_time = new QLabel(notice_dialog);
        notice_time->setObjectName(QString::fromUtf8("notice_time"));
        notice_time->setGeometry(QRect(10, 50, 121, 20));
        notice_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(notice_dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 120, 121, 20));
        ID = new QLabel(notice_dialog);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setGeometry(QRect(140, 20, 151, 16));
        name = new QLabel(notice_dialog);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(140, 50, 191, 16));
        time = new QLabel(notice_dialog);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(140, 80, 201, 16));

        retranslateUi(notice_dialog);

        QMetaObject::connectSlotsByName(notice_dialog);
    } // setupUi

    void retranslateUi(QDialog *notice_dialog)
    {
        ok_button->setText(QCoreApplication::translate("notice_dialog", "OK", nullptr));
        ignore_button->setText(QCoreApplication::translate("notice_dialog", "Ignore", nullptr));
        label->setText(QCoreApplication::translate("notice_dialog", "Request Time:", nullptr));
        label_2->setText(QCoreApplication::translate("notice_dialog", "Request ID:", nullptr));
        notice_time->setText(QCoreApplication::translate("notice_dialog", "Request Name:", nullptr));
        label_3->setText(QCoreApplication::translate("notice_dialog", "Message", nullptr));
        ID->setText(QString());
        name->setText(QString());
        time->setText(QString());
        Q_UNUSED(notice_dialog);
    } // retranslateUi

};

namespace Ui {
    class notice_dialog: public Ui_notice_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICE_DIALOG_H
