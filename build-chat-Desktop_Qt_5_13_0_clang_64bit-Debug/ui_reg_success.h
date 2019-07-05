/********************************************************************************
** Form generated from reading UI file 'reg_success.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_SUCCESS_H
#define UI_REG_SUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_reg_success
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QTextBrowser *ID;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ok;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *reg_success)
    {
        if (reg_success->objectName().isEmpty())
            reg_success->setObjectName(QString::fromUtf8("reg_success"));
        reg_success->resize(300, 200);
        reg_success->setMinimumSize(QSize(300, 200));
        reg_success->setMaximumSize(QSize(300, 200));
        verticalLayout_2 = new QVBoxLayout(reg_success);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(reg_success);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        ID = new QTextBrowser(reg_success);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setMinimumSize(QSize(0, 25));
        ID->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(ID);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        ok = new QPushButton(reg_success);
        ok->setObjectName(QString::fromUtf8("ok"));

        horizontalLayout->addWidget(ok);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(reg_success);

        QMetaObject::connectSlotsByName(reg_success);
    } // setupUi

    void retranslateUi(QDialog *reg_success)
    {
        reg_success->setWindowTitle(QCoreApplication::translate("reg_success", "Register Success", nullptr));
        label->setText(QCoreApplication::translate("reg_success", "Your ID:", nullptr));
        ok->setText(QCoreApplication::translate("reg_success", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg_success: public Ui_reg_success {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_SUCCESS_H
