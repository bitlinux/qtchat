/********************************************************************************
** Form generated from reading UI file 'group_chat_message.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_CHAT_MESSAGE_H
#define UI_GROUP_CHAT_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_group_chat_message
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *browser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;

    void setupUi(QDialog *group_chat_message)
    {
        if (group_chat_message->objectName().isEmpty())
            group_chat_message->setObjectName(QString::fromUtf8("group_chat_message"));
        group_chat_message->resize(414, 344);
        verticalLayout_2 = new QVBoxLayout(group_chat_message);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        browser = new QTextBrowser(group_chat_message);
        browser->setObjectName(QString::fromUtf8("browser"));

        horizontalLayout->addWidget(browser);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        close = new QPushButton(group_chat_message);
        close->setObjectName(QString::fromUtf8("close"));

        horizontalLayout_2->addWidget(close);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(group_chat_message);

        QMetaObject::connectSlotsByName(group_chat_message);
    } // setupUi

    void retranslateUi(QDialog *group_chat_message)
    {
        group_chat_message->setWindowTitle(QCoreApplication::translate("group_chat_message", "Dialog", nullptr));
        close->setText(QCoreApplication::translate("group_chat_message", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class group_chat_message: public Ui_group_chat_message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_CHAT_MESSAGE_H
