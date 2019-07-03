/********************************************************************************
** Form generated from reading UI file 'noticeitem.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICEITEM_H
#define UI_NOTICEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_noticeitem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *header_button;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *id_label;
    QLabel *name_label;
    QLabel *time_label;

    void setupUi(QWidget *noticeitem)
    {
        if (noticeitem->objectName().isEmpty())
            noticeitem->setObjectName(QString::fromUtf8("noticeitem"));
        noticeitem->resize(400, 100);
        horizontalLayout_2 = new QHBoxLayout(noticeitem);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        header_button = new QToolButton(noticeitem);
        header_button->setObjectName(QString::fromUtf8("header_button"));
        header_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(header_button);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        id_label = new QLabel(noticeitem);
        id_label->setObjectName(QString::fromUtf8("id_label"));

        verticalLayout->addWidget(id_label);

        name_label = new QLabel(noticeitem);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        verticalLayout->addWidget(name_label);


        horizontalLayout_3->addLayout(verticalLayout);

        time_label = new QLabel(noticeitem);
        time_label->setObjectName(QString::fromUtf8("time_label"));

        horizontalLayout_3->addWidget(time_label);


        horizontalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(noticeitem);

        QMetaObject::connectSlotsByName(noticeitem);
    } // setupUi

    void retranslateUi(QWidget *noticeitem)
    {
        noticeitem->setWindowTitle(QCoreApplication::translate("noticeitem", "Form", nullptr));
        header_button->setText(QCoreApplication::translate("noticeitem", "...", nullptr));
        id_label->setText(QCoreApplication::translate("noticeitem", "TextLabel", nullptr));
        name_label->setText(QCoreApplication::translate("noticeitem", "TextLabel", nullptr));
        time_label->setText(QCoreApplication::translate("noticeitem", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class noticeitem: public Ui_noticeitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICEITEM_H
