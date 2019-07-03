/********************************************************************************
** Form generated from reading UI file 'private_chat_message.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATE_CHAT_MESSAGE_H
#define UI_PRIVATE_CHAT_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_private_chat_message
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *browser;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;

    void setupUi(QDialog *private_chat_message)
    {
        if (private_chat_message->objectName().isEmpty())
            private_chat_message->setObjectName(QString::fromUtf8("private_chat_message"));
        private_chat_message->resize(413, 344);
        verticalLayout_2 = new QVBoxLayout(private_chat_message);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        browser = new QTextBrowser(private_chat_message);
        browser->setObjectName(QString::fromUtf8("browser"));

        horizontalLayout->addWidget(browser);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        close = new QPushButton(private_chat_message);
        close->setObjectName(QString::fromUtf8("close"));

        horizontalLayout_3->addWidget(close);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(private_chat_message);

        QMetaObject::connectSlotsByName(private_chat_message);
    } // setupUi

    void retranslateUi(QDialog *private_chat_message)
    {
        private_chat_message->setWindowTitle(QCoreApplication::translate("private_chat_message", "record", nullptr));
        close->setText(QCoreApplication::translate("private_chat_message", "CLOSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class private_chat_message: public Ui_private_chat_message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATE_CHAT_MESSAGE_H
