/********************************************************************************
** Form generated from reading UI file 'group_chat.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_CHAT_H
#define UI_GROUP_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_group_chat
{
public:
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *photo;
    QLabel *id;
    QLabel *name;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout1;
    QHBoxLayout *horizontalLayout_6;
    QTextBrowser *chat_browser;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *file;
    QPushButton *sendfile;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *records;
    QLabel *filename;
    QHBoxLayout *horizontalLayout_8;
    QTextEdit *textedit;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *send;
    QVBoxLayout *vLayout2;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineedit;
    QPushButton *change;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *member_browser;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addnew;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *group_chat)
    {
        if (group_chat->objectName().isEmpty())
            group_chat->setObjectName(QString::fromUtf8("group_chat"));
        group_chat->resize(594, 456);
        horizontalLayout_13 = new QHBoxLayout(group_chat);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        photo = new QLabel(group_chat);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(40, 40));

        horizontalLayout_5->addWidget(photo);

        id = new QLabel(group_chat);
        id->setObjectName(QString::fromUtf8("id"));

        horizontalLayout_5->addWidget(id);

        name = new QLabel(group_chat);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_5->addWidget(name);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_10->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_10);

        hLayout = new QHBoxLayout();
        hLayout->setObjectName(QString::fromUtf8("hLayout"));
        vLayout1 = new QVBoxLayout();
        vLayout1->setObjectName(QString::fromUtf8("vLayout1"));
        vLayout1->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        chat_browser = new QTextBrowser(group_chat);
        chat_browser->setObjectName(QString::fromUtf8("chat_browser"));
        chat_browser->setMinimumSize(QSize(350, 170));

        horizontalLayout_6->addWidget(chat_browser);


        vLayout1->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        file = new QPushButton(group_chat);
        file->setObjectName(QString::fromUtf8("file"));

        horizontalLayout_7->addWidget(file);

        sendfile = new QPushButton(group_chat);
        sendfile->setObjectName(QString::fromUtf8("sendfile"));

        horizontalLayout_7->addWidget(sendfile);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        records = new QPushButton(group_chat);
        records->setObjectName(QString::fromUtf8("records"));

        horizontalLayout_7->addWidget(records);


        vLayout1->addLayout(horizontalLayout_7);

        filename = new QLabel(group_chat);
        filename->setObjectName(QString::fromUtf8("filename"));

        vLayout1->addWidget(filename);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        textedit = new QTextEdit(group_chat);
        textedit->setObjectName(QString::fromUtf8("textedit"));
        textedit->setMinimumSize(QSize(0, 80));

        horizontalLayout_8->addWidget(textedit);


        vLayout1->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        send = new QPushButton(group_chat);
        send->setObjectName(QString::fromUtf8("send"));

        horizontalLayout_9->addWidget(send);


        vLayout1->addLayout(horizontalLayout_9);


        hLayout->addLayout(vLayout1);

        vLayout2 = new QVBoxLayout();
        vLayout2->setObjectName(QString::fromUtf8("vLayout2"));
        vLayout2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(group_chat);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(200, 16777215));

        verticalLayout_6->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineedit = new QLineEdit(group_chat);
        lineedit->setObjectName(QString::fromUtf8("lineedit"));
        lineedit->setMinimumSize(QSize(120, 0));
        lineedit->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(lineedit);

        change = new QPushButton(group_chat);
        change->setObjectName(QString::fromUtf8("change"));
        change->setMinimumSize(QSize(80, 0));
        change->setMaximumSize(QSize(65, 16777215));

        horizontalLayout->addWidget(change);


        verticalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_11->addLayout(verticalLayout_6);


        vLayout2->addLayout(horizontalLayout_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(group_chat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(group_chat);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        vLayout2->addLayout(horizontalLayout_2);

        member_browser = new QTextBrowser(group_chat);
        member_browser->setObjectName(QString::fromUtf8("member_browser"));
        member_browser->setMinimumSize(QSize(200, 180));
        member_browser->setMaximumSize(QSize(200, 16666));

        vLayout2->addWidget(member_browser);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        vLayout2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        addnew = new QPushButton(group_chat);
        addnew->setObjectName(QString::fromUtf8("addnew"));
        addnew->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(addnew);


        vLayout2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLayout2->addItem(verticalSpacer_2);


        hLayout->addLayout(vLayout2);


        verticalLayout_3->addLayout(hLayout);


        horizontalLayout_13->addLayout(verticalLayout_3);


        retranslateUi(group_chat);

        QMetaObject::connectSlotsByName(group_chat);
    } // setupUi

    void retranslateUi(QWidget *group_chat)
    {
        group_chat->setWindowTitle(QCoreApplication::translate("group_chat", "group_chat", nullptr));
        photo->setText(QCoreApplication::translate("group_chat", "PHOTO", nullptr));
        id->setText(QCoreApplication::translate("group_chat", "ID:", nullptr));
        name->setText(QCoreApplication::translate("group_chat", "NAME", nullptr));
        file->setText(QCoreApplication::translate("group_chat", "FILE", nullptr));
        sendfile->setText(QCoreApplication::translate("group_chat", "SEND FILE", nullptr));
        records->setText(QCoreApplication::translate("group_chat", "RECORDS", nullptr));
        filename->setText(QString());
        send->setText(QCoreApplication::translate("group_chat", "SEND", nullptr));
        label_4->setText(QCoreApplication::translate("group_chat", "NEW GROUP NAME:", nullptr));
        change->setText(QCoreApplication::translate("group_chat", "CHANGE", nullptr));
        label->setText(QCoreApplication::translate("group_chat", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("group_chat", "ONLINE", nullptr));
        addnew->setText(QCoreApplication::translate("group_chat", "ADD NEW MEMBER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class group_chat: public Ui_group_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_CHAT_H
