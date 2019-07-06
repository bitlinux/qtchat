/********************************************************************************
** Form generated from reading UI file 'private_chat.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATE_CHAT_H
#define UI_PRIVATE_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_private_chat
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *photo;
    QLabel *id;
    QLabel *name;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *chat_browser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *file;
    QPushButton *sendfile;
    QSpacerItem *horizontalSpacer;
    QPushButton *records;
    QLabel *filename;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textedit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *send;

    void setupUi(QWidget *private_chat)
    {
        if (private_chat->objectName().isEmpty())
            private_chat->setObjectName(QString::fromUtf8("private_chat"));
        private_chat->resize(458, 420);
        verticalLayout_2 = new QVBoxLayout(private_chat);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        photo = new QLabel(private_chat);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(40, 40));

        horizontalLayout->addWidget(photo);

        id = new QLabel(private_chat);
        id->setObjectName(QString::fromUtf8("id"));

        horizontalLayout->addWidget(id);

        name = new QLabel(private_chat);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout->addWidget(name);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        chat_browser = new QTextBrowser(private_chat);
        chat_browser->setObjectName(QString::fromUtf8("chat_browser"));
        chat_browser->setMinimumSize(QSize(400, 170));

        horizontalLayout_3->addWidget(chat_browser);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        file = new QPushButton(private_chat);
        file->setObjectName(QString::fromUtf8("file"));

        horizontalLayout_2->addWidget(file);

        sendfile = new QPushButton(private_chat);
        sendfile->setObjectName(QString::fromUtf8("sendfile"));

        horizontalLayout_2->addWidget(sendfile);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        records = new QPushButton(private_chat);
        records->setObjectName(QString::fromUtf8("records"));

        horizontalLayout_2->addWidget(records);


        verticalLayout->addLayout(horizontalLayout_2);

        filename = new QLabel(private_chat);
        filename->setObjectName(QString::fromUtf8("filename"));

        verticalLayout->addWidget(filename);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        textedit = new QTextEdit(private_chat);
        textedit->setObjectName(QString::fromUtf8("textedit"));
        textedit->setMinimumSize(QSize(0, 50));

        horizontalLayout_4->addWidget(textedit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        send = new QPushButton(private_chat);
        send->setObjectName(QString::fromUtf8("send"));

        horizontalLayout_6->addWidget(send);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(private_chat);

        QMetaObject::connectSlotsByName(private_chat);
    } // setupUi

    void retranslateUi(QWidget *private_chat)
    {
        private_chat->setWindowTitle(QCoreApplication::translate("private_chat", "private_chat", nullptr));
        photo->setText(QCoreApplication::translate("private_chat", "PHOTO", nullptr));
        id->setText(QCoreApplication::translate("private_chat", "ID:", nullptr));
        name->setText(QCoreApplication::translate("private_chat", "NAME:", nullptr));
        file->setText(QCoreApplication::translate("private_chat", "File", nullptr));
        sendfile->setText(QCoreApplication::translate("private_chat", "Send File", nullptr));
        records->setText(QCoreApplication::translate("private_chat", "Records", nullptr));
        filename->setText(QString());
        send->setText(QCoreApplication::translate("private_chat", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class private_chat: public Ui_private_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATE_CHAT_H
