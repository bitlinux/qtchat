/********************************************************************************
** Form generated from reading UI file 'creategroup.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUP_H
#define UI_CREATEGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateGroup
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *gpname_input;

    void setupUi(QDialog *CreateGroup)
    {
        if (CreateGroup->objectName().isEmpty())
            CreateGroup->setObjectName(QString::fromUtf8("CreateGroup"));
        CreateGroup->resize(335, 182);
        pushButton = new QPushButton(CreateGroup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 130, 89, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Google Sans"));
        pushButton->setFont(font);
        label = new QLabel(CreateGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 101, 16));
        label->setFont(font);
        gpname_input = new QLineEdit(CreateGroup);
        gpname_input->setObjectName(QString::fromUtf8("gpname_input"));
        gpname_input->setGeometry(QRect(90, 60, 161, 31));

        retranslateUi(CreateGroup);

        QMetaObject::connectSlotsByName(CreateGroup);
    } // setupUi

    void retranslateUi(QDialog *CreateGroup)
    {
        CreateGroup->setWindowTitle(QCoreApplication::translate("CreateGroup", "Create Group", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateGroup", "Create", nullptr));
        label->setText(QCoreApplication::translate("CreateGroup", "Group Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroup: public Ui_CreateGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUP_H
