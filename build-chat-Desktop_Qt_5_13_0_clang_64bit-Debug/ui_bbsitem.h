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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bbsitem
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *post_title;
    QHBoxLayout *horizontalLayout;
    QLabel *content_label;
    QLabel *poster_name;
    QLabel *px1;

    void setupUi(QWidget *bbsitem)
    {
        if (bbsitem->objectName().isEmpty())
            bbsitem->setObjectName(QString::fromUtf8("bbsitem"));
        bbsitem->resize(415, 104);
        gridLayout = new QGridLayout(bbsitem);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        post_title = new QPushButton(bbsitem);
        post_title->setObjectName(QString::fromUtf8("post_title"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        post_title->setFont(font);
        post_title->setCursor(QCursor(Qt::PointingHandCursor));
        post_title->setFlat(true);

        verticalLayout->addWidget(post_title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        content_label = new QLabel(bbsitem);
        content_label->setObjectName(QString::fromUtf8("content_label"));
        content_label->setMargin(0);
        content_label->setIndent(0);

        horizontalLayout->addWidget(content_label);

        poster_name = new QLabel(bbsitem);
        poster_name->setObjectName(QString::fromUtf8("poster_name"));
        poster_name->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(poster_name);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        px1 = new QLabel(bbsitem);
        px1->setObjectName(QString::fromUtf8("px1"));
        px1->setMaximumSize(QSize(16777215, 1));

        gridLayout->addWidget(px1, 1, 0, 1, 1);


        retranslateUi(bbsitem);

        QMetaObject::connectSlotsByName(bbsitem);
    } // setupUi

    void retranslateUi(QWidget *bbsitem)
    {
        bbsitem->setWindowTitle(QCoreApplication::translate("bbsitem", "Form", nullptr));
        post_title->setText(QCoreApplication::translate("bbsitem", "Post Title ", nullptr));
        content_label->setText(QCoreApplication::translate("bbsitem", "content", nullptr));
        poster_name->setText(QCoreApplication::translate("bbsitem", "poster_name", nullptr));
        px1->setText(QCoreApplication::translate("bbsitem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bbsitem: public Ui_bbsitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BBSITEM_H
