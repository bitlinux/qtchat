/********************************************************************************
** Form generated from reading UI file 'bbsitem.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BBSITEM_H
#define UI_BBSITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bbsitem
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *post_title;
    QHBoxLayout *horizontalLayout;
    QLabel *content_label;
    QLabel *poster_name;

    void setupUi(QWidget *bbsitem)
    {
        if (bbsitem->objectName().isEmpty())
            bbsitem->setObjectName(QString::fromUtf8("bbsitem"));
        bbsitem->resize(323, 97);
        verticalLayout_2 = new QVBoxLayout(bbsitem);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        post_title = new QPushButton(bbsitem);
        post_title->setObjectName(QString::fromUtf8("post_title"));
        QFont font;
        font.setPointSize(16);
        post_title->setFont(font);
        post_title->setCursor(QCursor(Qt::PointingHandCursor));
        post_title->setFlat(true);

        verticalLayout->addWidget(post_title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        content_label = new QLabel(bbsitem);
        content_label->setObjectName(QString::fromUtf8("content_label"));

        horizontalLayout->addWidget(content_label);

        poster_name = new QLabel(bbsitem);
        poster_name->setObjectName(QString::fromUtf8("poster_name"));

        horizontalLayout->addWidget(poster_name);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(bbsitem);

        QMetaObject::connectSlotsByName(bbsitem);
    } // setupUi

    void retranslateUi(QWidget *bbsitem)
    {
        bbsitem->setWindowTitle(QCoreApplication::translate("bbsitem", "Form", nullptr));
        post_title->setText(QCoreApplication::translate("bbsitem", "Post Title ", nullptr));
        content_label->setText(QCoreApplication::translate("bbsitem", "content", nullptr));
        poster_name->setText(QCoreApplication::translate("bbsitem", "poster_name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bbsitem: public Ui_bbsitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BBSITEM_H
