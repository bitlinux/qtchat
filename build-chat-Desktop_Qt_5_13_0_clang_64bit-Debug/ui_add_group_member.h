/********************************************************************************
** Form generated from reading UI file 'add_group_member.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_GROUP_MEMBER_H
#define UI_ADD_GROUP_MEMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_add_group_member
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineedit;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *add_group_member)
    {
        if (add_group_member->objectName().isEmpty())
            add_group_member->setObjectName(QString::fromUtf8("add_group_member"));
        add_group_member->resize(282, 187);
        verticalLayout_2 = new QVBoxLayout(add_group_member);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(add_group_member);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineedit = new QLineEdit(add_group_member);
        lineedit->setObjectName(QString::fromUtf8("lineedit"));

        horizontalLayout_4->addWidget(lineedit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(add_group_member);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add = new QPushButton(add_group_member);
        add->setObjectName(QString::fromUtf8("add"));
        add->setMinimumSize(QSize(85, 0));

        horizontalLayout->addWidget(add);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(add_group_member);

        QMetaObject::connectSlotsByName(add_group_member);
    } // setupUi

    void retranslateUi(QDialog *add_group_member)
    {
        add_group_member->setWindowTitle(QCoreApplication::translate("add_group_member", "Add Group Member", nullptr));
        label->setText(QCoreApplication::translate("add_group_member", "Input ID:", nullptr));
        pushButton->setText(QCoreApplication::translate("add_group_member", "Cancel", nullptr));
        add->setText(QCoreApplication::translate("add_group_member", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_group_member: public Ui_add_group_member {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_GROUP_MEMBER_H
