/********************************************************************************
** Form generated from reading UI file 'groupitem.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPITEM_H
#define UI_GROUPITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupitem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QToolButton *header_button;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *id_label;
    QLabel *name_label;

    void setupUi(QWidget *groupitem)
    {
        if (groupitem->objectName().isEmpty())
            groupitem->setObjectName(QString::fromUtf8("groupitem"));
        groupitem->resize(400, 101);
        horizontalLayout_2 = new QHBoxLayout(groupitem);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        header_button = new QToolButton(groupitem);
        header_button->setObjectName(QString::fromUtf8("header_button"));
        header_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(header_button);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        id_label = new QLabel(groupitem);
        id_label->setObjectName(QString::fromUtf8("id_label"));

        verticalLayout->addWidget(id_label);

        name_label = new QLabel(groupitem);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        verticalLayout->addWidget(name_label);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(groupitem);

        QMetaObject::connectSlotsByName(groupitem);
    } // setupUi

    void retranslateUi(QWidget *groupitem)
    {
        groupitem->setWindowTitle(QCoreApplication::translate("groupitem", "Form", nullptr));
        header_button->setText(QCoreApplication::translate("groupitem", "...", nullptr));
        id_label->setText(QCoreApplication::translate("groupitem", "TextLabel", nullptr));
        name_label->setText(QCoreApplication::translate("groupitem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupitem: public Ui_groupitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPITEM_H
