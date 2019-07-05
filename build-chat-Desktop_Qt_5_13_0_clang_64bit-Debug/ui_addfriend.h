/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddFriend
{
public:
    QPushButton *aply_but;
    QLabel *id_but;
    QLineEdit *id_input;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *AddFriend)
    {
        if (AddFriend->objectName().isEmpty())
            AddFriend->setObjectName(QString::fromUtf8("AddFriend"));
        AddFriend->resize(432, 356);
        aply_but = new QPushButton(AddFriend);
        aply_but->setObjectName(QString::fromUtf8("aply_but"));
        aply_but->setGeometry(QRect(160, 320, 89, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Google Sans"));
        aply_but->setFont(font);
        id_but = new QLabel(AddFriend);
        id_but->setObjectName(QString::fromUtf8("id_but"));
        id_but->setGeometry(QRect(80, 30, 21, 17));
        id_but->setFont(font);
        id_input = new QLineEdit(AddFriend);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(80, 50, 241, 31));
        label = new QLabel(AddFriend);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 100, 121, 20));
        textEdit = new QTextEdit(AddFriend);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 130, 241, 161));

        retranslateUi(AddFriend);

        QMetaObject::connectSlotsByName(AddFriend);
    } // setupUi

    void retranslateUi(QDialog *AddFriend)
    {
        AddFriend->setWindowTitle(QCoreApplication::translate("AddFriend", "Add Friend", nullptr));
        aply_but->setText(QCoreApplication::translate("AddFriend", "Send", nullptr));
        id_but->setText(QCoreApplication::translate("AddFriend", "ID", nullptr));
        label->setText(QCoreApplication::translate("AddFriend", "Apply Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriend: public Ui_AddFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
