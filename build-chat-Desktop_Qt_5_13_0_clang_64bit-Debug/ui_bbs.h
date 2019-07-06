/********************************************************************************
** Form generated from reading UI file 'bbs.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BBS_H
#define UI_BBS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bbs
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *bbs_list;
    QVBoxLayout *verticalLayout;
    QPushButton *postButton;
    QPushButton *shared_button;
    QPushButton *quitButton;

    void setupUi(QWidget *bbs)
    {
        if (bbs->objectName().isEmpty())
            bbs->setObjectName(QString::fromUtf8("bbs"));
        bbs->resize(597, 472);
        horizontalLayout_2 = new QHBoxLayout(bbs);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bbs_list = new QListWidget(bbs);
        bbs_list->setObjectName(QString::fromUtf8("bbs_list"));

        horizontalLayout->addWidget(bbs_list);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        postButton = new QPushButton(bbs);
        postButton->setObjectName(QString::fromUtf8("postButton"));
        postButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(postButton);

        shared_button = new QPushButton(bbs);
        shared_button->setObjectName(QString::fromUtf8("shared_button"));
        shared_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(shared_button);

        quitButton = new QPushButton(bbs);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(quitButton);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(bbs);

        QMetaObject::connectSlotsByName(bbs);
    } // setupUi

    void retranslateUi(QWidget *bbs)
    {
        bbs->setWindowTitle(QCoreApplication::translate("bbs", "Form", nullptr));
        postButton->setText(QCoreApplication::translate("bbs", "Post", nullptr));
        shared_button->setText(QCoreApplication::translate("bbs", "File Sharing", nullptr));
        quitButton->setText(QCoreApplication::translate("bbs", "Quit BBS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bbs: public Ui_bbs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BBS_H
